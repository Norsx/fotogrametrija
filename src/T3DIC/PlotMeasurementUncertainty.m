clear all
close all
clc
set(0, 'DefaultAxesFontName', 'times');
set(0, 'DefaultAxesFontSize', 30);
set(0, 'DefaultColorbarFontSize', 30); % Change 20 to your desired font size
set(0, 'DefaultLegendFontSize', 30);
set(0,'defaultTextInterpreter','latex');
addpath(genpath([pwd,'\Functions\']))

%% 1 - Load Data

Path = uigetdir;
SaveFolder = [Path,'\'];

mat_files = dir(fullfile(Path,'/','Uncertainty*mat'));
mat_files = {mat_files.name}';
mat_files = natsort(mat_files);
mat_files_num = length(mat_files);

for ii = 1 : mat_files_num

num = regexp(mat_files{ii},'[\d\.]+','match');
num = str2double(num);

Mesh_size(ii,1) = num;

eval(['Mesh_',num2str(Mesh_size(ii,1)),' = load([SaveFolder,''Uncertainty_msh_',num2str(Mesh_size(ii,1)),'.mat''],''Unc'');'])

end

%% Rearrange the data

for ii = 1 : mat_files_num
    eval(['U_unc(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.U_unc;'])
    eval(['Ux_unc(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.Ux_unc;'])
    eval(['Uy_unc(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.Uy_unc;'])
    eval(['E_unc(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.E_1;'])
    eval(['E_xx(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.Exx_unc;'])
    eval(['E_yy(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.Eyy_unc;'])
    eval(['E_xy(ii,1) = Mesh_',num2str(Mesh_size(ii,1)),'.Unc.Exy_unc;'])
end

%% loglog U uncertainty

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,U_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_U$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_u.png'],'Resolution',600)

% close all

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,Ux_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{U_x}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_ux.png'],'Resolution',600)

% close all

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,Uy_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{U_y}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_uy.png'],'Resolution',600)

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,Ux_unc,'b','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
hold on
loglog(Mesh_size,Uy_unc,'r','LineWidth',2,'Marker','+','MarkerEdgeColor','b')
loglog(Mesh_size,U_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{U}$','Interpreter','latex')
legend('$U_x$','$U_y$','$U_{magnitude}$','Location','eastoutside','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_u_comparison.png'],'Resolution',600)
%% loglog eps uncertainty

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,E_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{\epsilon_1}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_eps1.png'],'Resolution',600)

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,E_xx,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{\epsilon_{xx}}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_epsxx.png'],'Resolution',600)

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,E_yy,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{\epsilon_{yy}}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_epsyy.png'],'Resolution',600)

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,E_xy,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{\gamma_{xy}}$','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_epsxy.png'],'Resolution',600)

ha = figure;
set(gcf,'Position',[50 50 1200 800])
loglog(Mesh_size,E_xx,'r','LineWidth',2,'Marker','+','MarkerEdgeColor','b')
hold on
loglog(Mesh_size,E_yy,'b','LineWidth',2,'Marker','+','MarkerEdgeColor','b')
loglog(Mesh_size,E_xy,'g','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
loglog(Mesh_size,E_unc,'k','LineWidth',2,'Marker','+','MarkerEdgeColor','r')
xlabel('Mesh element size','Interpreter','latex')
ylabel('$\sigma_{\epsilon}$','Interpreter','latex')
legend('$\epsilon_{xx}$','$\epsilon_y$','$\gamma_{xy}$','$\epsilon_1$','Location','eastoutside','Interpreter','latex')
exportgraphics(ha,[SaveFolder,'Sigma_eps_comparison.png'],'Resolution',600)

close all