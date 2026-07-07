function out = RunUncertaintyBatch
% RUNUNCERTAINTYBATCH  Non-interactive measurement-uncertainty analysis.
%
% Runs the global T3 DIC algorithm (same as RunMeasurementUncertainty.m /
% GlobalT3DIC.m, without the GUI steps) on the first 20 images of the
% recording, acquired with the specimen UNLOADED, and computes the standard
% displacement/strain uncertainty via CalculateMeasurementUncertainty.
%
%  a) reference measurement mesh of both cameras (DICresults_msh_0),
%  b) a mesh-size study on camera 1 (meshes regenerated over the same ROI
%     with generateMesh, GeometricOrder='linear', Hgrad=2, Hmax = element size)
%     to reproduce the sigma-vs-element-size plots of PlotMeasurementUncertainty.m.
%
% Output: data/processed/uncertainty_<ddmmyyyy_hhmmss>/

here = fileparts(mfilename('fullpath'));
addpath(genpath(fullfile(here,'Functions')));
root = fullfile(here,'..','..');
raw  = fullfile(root,'data','raw');

nim     = 20;       % unloaded images acquired for the uncertainty estimate
px_size = 0.0502;   % mm per pixel (see Functions/GlobalT3DIC.m)

outDir = fullfile(root,'data','processed', ...
    ['uncertainty_' char(datetime('now','Format','ddMMyyyy_HHmmss'))]);
mkdir(outDir);

%% a) reference measurement mesh, both cameras
cams = {'cam1','cam2'};
base = struct();
for c = 1:2
    camPath = fullfile(raw,cams{c});
    D = load(fullfile(camPath,'DICresults','DICresults_msh_0.mat'),'Mesh');
    [U,rms_r,Mesh] = dicLoop(camPath, D.Mesh, nim);
    Unc = CalculateMeasurementUncertainty(Mesh,U,nim,px_size);
    base.(cams{c}) = struct('Unc',Unc,'rms_r',rms_r);
    save(fullfile(outDir,['Uncertainty_' cams{c} '_msh_0.mat']),'Unc','U','rms_r');
    fprintf('--- %s (measurement mesh): sigma_U = %.4e mm (%.4f px)\n', ...
        cams{c}, Unc.U_unc, Unc.U_unc/px_size);
end

% rms residual plot (as in RunMeasurementUncertainty.m)
ha = figure('Visible','off','Position',[50 50 900 550]);
plot(1:nim, base.cam1.rms_r,'k','LineWidth',2); hold on
plot(1:nim, base.cam2.rms_r,'k--','LineWidth',2);
xlabel('Slika \#','Interpreter','latex')
ylabel('rms($\rho$) [siva razina]','Interpreter','latex')
legend('kamera 1','kamera 2','Location','best'); grid on
exportgraphics(ha, fullfile(outDir,'rms_rho.png'),'Resolution',300);
close(ha)

%% b) mesh-size study on camera 1
camPath = fullfile(raw,'cam1');
D = load(fullfile(camPath,'DICresults','DICresults_msh_0.mat'),'Mesh');
MeshBase = D.Mesh;
sizes = [5 6 8 10 12 16 20 26 32];

% ROI boundary polygon from the measurement mesh (ordered free boundary)
xy = double(MeshBase.coordinates(:,1:2));
TR = triangulation(double(MeshBase.connectivity), xy);
fb = freeBoundary(TR);
loop = fb(1,:); fb(1,:) = [];
while ~isempty(fb)
    idx = find(fb(:,1)==loop(end),1);
    if isempty(idx)
        idx = find(fb(:,2)==loop(end),1);
        fb(idx,:) = fliplr(fb(idx,:));
    end
    loop(end+1) = fb(idx,2); %#ok<AGROW>
    fb(idx,:) = [];
end
polyXY = xy(loop(1:end-1),:);

elem_px = []; res = struct('U_unc',[],'Ux_unc',[],'Uy_unc',[], ...
    'Exx_unc',[],'Eyy_unc',[],'Exy_unc',[],'E_1',[]);
k = 0;
for sz = sizes
    try
        Mesh = meshFromPolygon(polyXY, sz, MeshBase);
        [U,rms_r,Mesh] = dicLoop(camPath, Mesh, nim); %#ok<ASGLU>
        Unc = CalculateMeasurementUncertainty(Mesh,U,nim,px_size);
    catch ME
        fprintf('size %d failed: %s\n', sz, ME.message);
        continue
    end
    k = k + 1;
    elem_px(k,1)   = Unc.avg_elem_l / px_size; %#ok<AGROW>
    res.U_unc(k,1)   = Unc.U_unc;   res.Ux_unc(k,1) = Unc.Ux_unc;
    res.Uy_unc(k,1)  = Unc.Uy_unc;  res.Exx_unc(k,1) = Unc.Exx_unc;
    res.Eyy_unc(k,1) = Unc.Eyy_unc; res.Exy_unc(k,1) = Unc.Exy_unc;
    res.E_1(k,1)     = Unc.E_1;
    save(fullfile(outDir,['Uncertainty_msh_' num2str(sz) '.mat']),'Unc','rms_r');
    fprintf('--- mesh size %2d px (avg elem %.2f px): sigma_U = %.4e mm, sigma_eps1 = %.4e\n', ...
        sz, elem_px(k), Unc.U_unc, Unc.E_1);
end

% sigma_U vs element size (as in PlotMeasurementUncertainty.m)
ha = figure('Visible','off','Position',[50 50 900 620]);
loglog(elem_px,res.Ux_unc,'b','LineWidth',2,'Marker','+'); hold on
loglog(elem_px,res.Uy_unc,'r','LineWidth',2,'Marker','+');
loglog(elem_px,res.U_unc,'k','LineWidth',2,'Marker','+');
xlabel('Velicina elementa $\ell$ [px]','Interpreter','latex')
ylabel('$\sigma_U$ [mm]','Interpreter','latex')
legend('$U_x$','$U_y$','$U$','Location','northeast','Interpreter','latex')
grid on
exportgraphics(ha, fullfile(outDir,'Sigma_u_comparison.png'),'Resolution',300);
close(ha)

% sigma_eps vs element size
ha = figure('Visible','off','Position',[50 50 900 620]);
loglog(elem_px,res.Exx_unc,'r','LineWidth',2,'Marker','+'); hold on
loglog(elem_px,res.Eyy_unc,'b','LineWidth',2,'Marker','+');
loglog(elem_px,res.Exy_unc,'g','LineWidth',2,'Marker','+');
loglog(elem_px,res.E_1,'k','LineWidth',2,'Marker','+');
xlabel('Velicina elementa $\ell$ [px]','Interpreter','latex')
ylabel('$\sigma_\varepsilon$ [--]','Interpreter','latex')
legend('$\varepsilon_{xx}$','$\varepsilon_{yy}$','$\gamma_{xy}$','$\varepsilon_1$', ...
    'Location','northeast','Interpreter','latex')
grid on
exportgraphics(ha, fullfile(outDir,'Sigma_eps_comparison.png'),'Resolution',300);
close(ha)

out = struct('outDir',outDir,'base',base,'elem_px',elem_px,'res',res);
save(fullfile(outDir,'summary.mat'),'-struct','out');
fprintf('Output: %s\n', outDir);
end

% -------------------------------------------------------------------------
function Mesh = meshFromPolygon(polyXY, sz, MeshBase)
% Regenerate a T3 mesh over the ROI polygon with target element size sz [px]
% (same generateMesh settings as AdjustMeshElementSize.m).
ps = polyshape(polyXY(:,1), polyXY(:,2));
tri = triangulation(ps);
model = createpde;
geometryFromMesh(model, tri.Points', tri.ConnectivityList');
generateMesh(model,'GeometricOrder','linear','Hgrad',2,'Hmax',sz);
nodes = model.Mesh.Nodes';
elems = model.Mesh.Elements';
Mesh.coordinates  = [nodes, zeros(size(nodes,1),1)];
Mesh.connectivity = elems;
Mesh.nodes        = (1:size(nodes,1))';
Mesh.elements     = (1:size(elems,1))';
Mesh = MeshCheckUpsideDown(Mesh);
Mesh.MeshSize = sz;
Mesh.X = MeshBase.X; Mesh.Y = MeshBase.Y; Mesh.Npx = MeshBase.Npx;
end

% -------------------------------------------------------------------------
function [U,rms_r,Mesh] = dicLoop(Path, Mesh, im_num)
% Global T3 DIC on the first im_num images (algorithm identical to
% RunMeasurementUncertainty.m: SSD residual, linear image interpolation).
images = dir(fullfile(Path,'*.png'));
images = natsort({images.name}');

f = double(imread(fullfile(Path,images{1})));
[n,m] = size(f);
[Y,X] = meshgrid(1:m,1:n);
Mesh.X = X; Mesh.Y = Y; Mesh.Npx = numel(X);
[dfy,dfx] = gradient(f);

[PSI_X,PSI_Y] = T3ShapeFun(Mesh);
Mask = reshape(full(any(PSI_X,2) | any(PSI_Y,2)), n, m);
Mesh.Mask = Mask;
psi_x = PSI_X(Mask,:); psi_y = PSI_Y(Mask,:);
clear PSI_X PSI_Y

L = psi_x.*dfx(Mask) + psi_y.*dfy(Mask);
M = sparse(L'*L);
if condest(M) > 10e4
    M = sparse(M + 1e-3*max(eigs(M,10))*eye(size(M,1)));
end

nn = length(Mesh.nodes); ndof = 2*nn;
min_it = 5; max_it = 200;
x = X(Mask); y = Y(Mask);
a = zeros(ndof,im_num);
U = cell(1,im_num); rms_r = zeros(im_num,1);
for im = 1:im_num
    g = double(imread(fullfile(Path,images{im})));
    F = griddedInterpolant(X,Y,g,'linear');
    it = 0; r_old = Inf; converged = false; r = 0;
    while ~converged
        it = it + 1;
        if im > 1 && it == 1
            Vx = psi_x*a(:,im-1); Vy = psi_y*a(:,im-1);
        else
            Vx = psi_x*a(:,im);   Vy = psi_y*a(:,im);
        end
        ghat = F(x+Vx, y+Vy);
        rho  = f(Mask) - ghat;
        r    = rms(rho);
        dr   = r - r_old;
        b  = L'*rho;
        da = M \ b;
        if im > 1 && it == 1
            a(:,im) = a(:,im-1) + da;
        else
            a(:,im) = a(:,im) + da;
        end
        if (abs(dr) < 1e-4 && it > min_it) || it == max_it
            converged = true;
        end
        r_old = r;
    end
    rms_r(im) = r;
    U{im} = [a(2:2:ndof,im), a(1:2:ndof,im)];
end
end
