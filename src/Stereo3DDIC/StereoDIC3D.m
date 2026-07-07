function res = StereoDIC3D(varargin)
% STEREODIC3D  Stereo digital image correlation (3D) main driver.
%
%   res = StereoDIC3D()                 % all frames, save results + plots
%   res = StereoDIC3D('nFrames',N)      % subsample to N frames
%   res = StereoDIC3D('save',false,'plot',false)
%   res = StereoDIC3D('clean',false)    % disable edge-node outlier cleaning
%
% Reconstructs 3D surface displacement and strain fields from the per-camera
% 2D DIC results (already computed by T3DIC) via stereo triangulation with the
% given projection matrices Pi1/Pi2. Only triangulation + surface strain are new;
% the correlation itself is reused from the existing 2D pipeline.
%
% 'clean' (default true) applies cleanEdgeNodes to the per-camera 2D fields
% before triangulation: nodes whose displacement deviates from the median of
% their mesh neighbours by more than 'cleanTol' px (default 3) are replaced by
% that median. This repairs isolated boundary nodes with degraded correlation
% without touching the rest of the field or any algorithm step.

p = inputParser;
p.addParameter('nFrames',[]);
p.addParameter('save',true);
p.addParameter('plot',true);
p.addParameter('clean',true);
p.addParameter('cleanTol',3);
p.parse(varargin{:});
opt = p.Results;

here = fileparts(mfilename('fullpath'));
addpath(genpath(here));
root = fullfile(here,'..','..');
raw  = fullfile(root,'data','raw');

% --- calibration (given projection matrices) ---
C  = load(fullfile(raw,'Calib_plus_3D_mesh.mat'),'Pi1','Pi2');
P1 = C.Pi1;  P2 = C.Pi2;

% --- per-camera 2D DIC results (identical 252-node mesh, node-to-node match) ---
D1 = load(fullfile(raw,'cam1','DICresults','DICresults_msh_0.mat'),'Mesh','U');
D2 = load(fullfile(raw,'cam2','DICresults','DICresults_msh_0.mat'),'Mesh','U');
conn = D1.Mesh.connectivity;
xy1  = D1.Mesh.coordinates(:,1:2);        % cam1 reference pixels [x,y]
xy2  = D2.Mesh.coordinates(:,1:2);        % cam2 reference pixels

% --- optional cleaning of isolated outlier nodes (degraded edge correlation) ---
cleanInfo = struct('cam1',[],'cam2',[]);
if opt.clean
    [D1.U, cleanInfo.cam1] = cleanEdgeNodes(D1.U, conn, opt.cleanTol);
    [D2.U, cleanInfo.cam2] = cleanEdgeNodes(D2.U, conn, opt.cleanTol);
    fprintf('cleanEdgeNodes (tol %.1f px): cam1 nodes [%s], cam2 nodes [%s]\n', ...
        opt.cleanTol, num2str(cleanInfo.cam1.nodes), num2str(cleanInfo.cam2.nodes));
end

nAll = numel(D1.U);
if isempty(opt.nFrames), frames = 1:nAll; else, frames = round(linspace(1,nAll,opt.nFrames)); end
nF = numel(frames);

% --- reference 3D shape (recovers MeshDef) ---
Xref = stereoTriangulate(xy1, xy2, P1, P2);

% --- per-frame 3D displacement + strain evolution ---
U3D   = cell(nF,1);
Umax  = zeros(nF,1);  Uzmax = zeros(nF,1);  E1max = zeros(nF,1);
for k = 1:nF
    t = frames(k);
    X = stereoTriangulate(xy1 + D1.U{t}, xy2 + D2.U{t}, P1, P2);   % same-index pairing
    U3D{k} = X - Xref;
    [~,Ep] = surfaceStrains(Xref, conn, U3D{k});
    Umax(k)  = max(vecnorm(U3D{k},2,2));
    Uzmax(k) = max(abs(U3D{k}(:,3)));
    E1max(k) = max(Ep(:,1));
end
[Ecomp,Eprin,Evm] = surfaceStrains(Xref, conn, U3D{end});

res = struct('Xref',Xref,'conn',conn,'frames',frames,'U3D',{U3D}, ...
             'Ecomp',Ecomp,'Eprin',Eprin,'Evm',Evm, ...
             'Umax',Umax,'Uzmax',Uzmax,'E1max',E1max, ...
             'clean',cleanInfo,'u1last',D1.U{frames(end)},'u2last',D2.U{frames(end)});

% --- output folder (project rule: data/processed/<source_ddmmyyyy_hhmmss>) ---
if opt.save || opt.plot
    outDir = fullfile(root,'data','processed',['stereo_' char(datetime('now','Format','ddMMyyyy_HHmmss'))]);
    if ~exist(outDir,'dir'), mkdir(outDir); end
end
if opt.save
    save(fullfile(outDir,'stereo3d_results.mat'),'-struct','res','-v7.3');
end

% --- visualization (built-in trisurf / patch) ---
if opt.plot
    Ud = U3D{end};  Xd = Xref + Ud;
    f1 = figure('Visible','off','Position',[100 100 900 700]);
    trisurf(conn, Xd(:,1),Xd(:,2),Xd(:,3), vecnorm(Ud,2,2), 'EdgeColor','none');
    axis equal tight; colorbar; colormap turbo; view(3);
    title('Iznos 3D pomaka |U| — deformirani oblik'); xlabel x; ylabel y; zlabel z;
    exportgraphics(f1, fullfile(outDir,'disp_magnitude.png'),'Resolution',150);

    f2 = figure('Visible','off','Position',[100 100 900 700]);
    patch('Faces',conn,'Vertices',Xref,'FaceVertexCData',Eprin(:,1), ...
          'FaceColor','flat','EdgeColor','none');
    axis equal tight; colorbar; colormap turbo; view(3);
    clim([0 prctile(Eprin(:,1),97)]);          % robust range (edge-noise outliers)
    title('Glavna deformacija E_1'); xlabel x; ylabel y; zlabel z;
    exportgraphics(f2, fullfile(outDir,'strain_E1.png'),'Resolution',150);

    f3 = figure('Visible','off','Position',[100 100 900 500]);
    plot(frames,Umax,'LineWidth',1.5); hold on; plot(frames,Uzmax,'LineWidth',1.5);
    grid on; xlabel('Frame'); ylabel('Pomak (kalibracijske jedinice)');
    legend('max |U|','max |U_z| (izvanravninski)','Location','northwest');
    title('Evolucija pomaka');
    exportgraphics(f3, fullfile(outDir,'disp_evolution.png'),'Resolution',150);
    close([f1 f2 f3]);
end

if opt.save || opt.plot, fprintf('Output: %s\n', outDir); end
fprintf('StereoDIC3D done: %d frames, %d nodes, %d elements.\n', nF, size(Xref,1), size(conn,1));
end
