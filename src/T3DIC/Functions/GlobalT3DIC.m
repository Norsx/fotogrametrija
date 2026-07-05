clear all
close all
clc
set(0,'defaultAxesFontSize',18)
addpath(genpath([pwd,'\Functions\']))
set(0, 'DefaultAxesFontName', 'times');
set(0, 'DefaultAxesFontSize', 30);
set(0, 'DefaultColorbarFontSize', 30); % Change 20 to your desired font size
set(0, 'DefaultLegendFontSize', 30);
set(0,'defaultTextInterpreter','latex');
addpath(genpath([pwd,'\Functions\']))

%% 1 - Load Images
%lala
Path = uigetdir;

SaveFolder = [Path,'\DICresults\'];
mkdir(SaveFolder)

images = dir(fullfile(Path,'/','*tif'));
images = {images.name}';
images = natsort(images);
im_num = length(images);

% f = double(imread([Path,'\',images{1}]));
f = imread([Path,'\',images{1}]);
% f = rgb2gray(f);
f = double(f);


[n,m] = size(f);

figure;
colormap gray
imagesc(f)
xlabel('y')
ylabel('x')
axis image

% Pixel coordinate matrix

[Y,X] = meshgrid(1:m,1:n);

%% 1.1 - Images for measurement uncertainty
nim = 100;
flag_uncertainty = 0;
%% 1.2 - Define image scale
% Input the ratio between pixels size and milimeters
px_size = 0.0502;

%% 2 - Image Gradient
% -------------------------------------------------------------------------

[dfy, dfx] = gradient(f);

%% 3 - Mesh

MeshGeneration

%% 4 - Shape functions
% -------------------------------------------------------------------------
Mesh.Npx = length(X(:));
Mesh.X = X;
Mesh.Y = Y;
[PSI_X,PSI_Y] = T3ShapeFun(Mesh);

psi_x = PSI_X(Mask,:);
psi_y = PSI_Y(Mask,:);
clear PSI_X PSI_Y
% keyboard

%% 5 - Hessian (M)
% -------------------------------------------------------------------------
L = psi_x.*dfx(Mask) + psi_y.*dfy(Mask);
M = L' * L;
fprintf(['Hessian matrix conditioning: ', num2str(condest(M)),'\n'])

if condest(M) > 10e4
    M = M + 1e-3*max(eigs(M,10))*eye(size(M,1));

    fprintf(['Hessian matrix conditioning after Tikhonov: ', num2str(condest(M)),'\n'])
end
% keyboard

%% DIC Loop
% -------------------------------------------------------------------------
flag_plot_res = 0;
% 0-no plot
% 1-plot for converged solution
% 2-plot all iterations
close all
nn = length(Mesh.nodes);
ndof = 2*nn; %num nodes * 2
cmap = colorbrewer('RdBu');
min_it = 5;
max_it = 200;
% I = 1 : 300 : numel(X(Mask));
amp = 1;
% im_num = 30;
im_skip = 1;
y=Y(Mask);
x=X(Mask);
flag_memory_save = 0;

if flag_plot_res
    figure
    drawnow
end
clear r dr da a rms_r Vx Vy U
a = zeros(ndof,im_num);
count = 0;
for im = 1 : im_skip : im_num
    count = count + 1;
    if flag_plot_res
        clf    % keyboard
    end
    it = 0;
    r_old = Inf;
    converged = false;

    % g = double(imread([Path,'\',images{im}]));
    g = imread([Path,'\',images{im}]);
    % g = rgb2gray(g);
    g = double(g);

    while not(converged)
        it = it + 1;
        % Compute V
        if im == 1
            Vx = (psi_x*a(:,count));
            Vy = (psi_y*a(:,count));
        else
            if it == 1
                Vx = (psi_x*a(:,count-1));
                Vy = (psi_y*a(:,count-1));
            else
                Vx = (psi_x*a(:,count));
                Vy = (psi_y*a(:,count));
            end
        end
        %% 6. Evaluate ghat
        F = griddedInterpolant(X, Y, g, 'linear');
        ghat = F(x+Vx, y+Vy);
        % keyboard
        %% 7. residual
        rho = f(Mask) - ghat;
        % rho = ghat - f(Mask);
        if ~flag_memory_save
            res{count} = zeros(size(f));
            res{count}(Mask) = rho;
        end
        r{count}(it) = rms(rho);
        dr = r{count}(it) - r_old;
        
        %% 8. Second member

        b = transpose(L)*rho;

        %% 9. solve linear system

        da = M \ b;
        
        if im ==1
            a(:,count) = a(:,count) + da;
        else
            if it == 1
                a(:,count) = a(:,count-1) + da;
            else
                a(:,count) = a(:,count) + da;
            end
        end
        %% 10. test for convergence
        if abs(dr) < 10^-4 && it > min_it
            % promjena pomaka 10^-4, najbolji rezultat uzeti gdje je
            % najmanji r
            fprintf('Img: %3d, Iter: %3d, residual: %10.3e, dr: %10.3e norm(da): %10.3e \n', im, it, r{count}(it), dr, norm(da))
            fprintf('Algorithm converged \n')
            % fprintf('==========================================================\n')

            converged = true;
            if flag_plot_res
                PlotResidFieldIterative
            end
            break
        else
            fprintf('Img: %3d, Iter: %3d, residual: %10.3e, dr: %10.3e norm(da): %10.3e \n', im, it, r{count}(it), dr, norm(da))
            % fprintf('==========================================================\n')
            converged = false;
            r_old = r{count}(it);
            if it == max_it
                fprintf('Algorithm reached max. iteration \n')
                break
            end
        end

    end
    rms_r(count,1) = r{count}(it);
    U{count}(:,1) = a(2:2:ndof,count);
    U{count}(:,2) = a(1:2:ndof,count);

end

% return

Us = cellfun(@(x) x.*px_size,U,'UniformOutput',false);

E = MeshCalculateStrains(Mesh,Us,'Principal',1);

PlotMesh(Mesh);
PlotMesh(Mesh,'Field',Us);
PlotMesh(Mesh,'Field',E);

PlotMesh(Mesh,'Deformed',U)
% colormap hot

PlotResidField(res)

figure;
plot(rms_r,'k','LineWidth',2)
xlabel('Img \#','Interpreter','latex')
ylabel('rms($\rho$)','Interpreter','latex')
% print

save([SaveFolder,'DICresults_msh_',num2str(Mesh.MeshSize),'.mat'],'U','Us','Mesh','rms_r')
if ~flag_memory_save
    save([SaveFolder,'DICresid_msh_',num2str(Mesh.MeshSize),'.mat'],'res', '-v7.3')
end
%% Measurement uncertainty

if flag_uncertainty
    Unc = CalculateMeasurementUncertainty(Mesh,U,nim,px_size);
    save([SaveFolder,'Uncertainty_msh_',num2str(Mesh.MeshSize),'.mat'],'Unc')
end

%% END OF SCRIPT %%
return

% for petlja za skaliranje pomaka u mm
