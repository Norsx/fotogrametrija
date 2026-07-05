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

%% Load Data
factor = 10;
im = 50;
[file,location] = uigetfile('*.mat','Select save data');
load([location,file],'Mesh','U')

%% Create Save path

StrainDataFolder = [location,'StrainData\'];
mkdir(StrainDataFolder)

%% Calculate strains

E = MeshCalculateStrains(Mesh,U,'NodeExtrap',1); % regular strains
Eprinc = MeshCalculateStrains(Mesh,U,'Principal',1); % principal strains

%% Plot Strains

PlotMesh(Mesh,'Field',E);
PlotMesh(Mesh,'Field',Eprinc);

%% Virtual gauge

[virtgauge,Agauge] = Define_virtual_gauge(Eprinc,length(Eprinc)-im,StrainDataFolder,Mesh);
A = MeshArea(Mesh);
for inc = 1 : length(Eprinc)
    Gauge(inc,:) = sum(E{inc}(virtgauge,:).*repmat(A(virtgauge),1,3))./Agauge;
    Gauge_princ(inc,:) = sum(Eprinc{inc}(virtgauge,:).*repmat(A(virtgauge),1,3))./Agauge;
end

save([StrainDataFolder,'GaugeData_msh_',num2str(Mesh.MeshSize),'.mat'],'Gauge')

%% Plot figures
% eps 1
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(Gauge_princ(:,1).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_1$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_1_gauge.png'],'Resolution',300)
% eps X
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(Gauge(:,1).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_x$, \%','Interpreter','latex')
ylim([-1 1]*factor)
exportgraphics(ha,[StrainDataFolder,'eps_xx_gauge.png'],'Resolution',300)
% eps X
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(Gauge(:,2).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_y$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_yy_gauge.png'],'Resolution',300)
% eps X
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(Gauge(:,3).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{xy}$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_xy_gauge.png'],'Resolution',300)

% combined
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(Gauge_princ(:,1).*100,'k','LineWidth',2)
hold on
plot(Gauge(:,1).*100,'r','LineWidth',2)
plot(Gauge(:,2).*100,'g','LineWidth',2)
plot(Gauge(:,3).*100,'b','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon$, \%','Interpreter','latex')
legend('$\varepsilon_1$','$\varepsilon_x$','$\varepsilon_y$','$\varepsilon_{xy}$','Location','eastoutside','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'combined.png'],'Resolution',300)
%% Nodal strains
close all
pos = Mesh.coordinates';
Nn = length(Mesh.nodes);
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
PlotMesh(Mesh,'Field',Eprinc{length(Eprinc)-im}(:,1))
clim([0 0.1])
colormap hot
hold on
counter = 0;
answer = 'Yes';
while ~strcmpi(answer,'No')
    pause(1)
    counter = counter + 1;
    [xx,yy] = ginput(1);
    for jj=1:Nn
        dist(counter,jj)= sqrt(  (pos(1,jj)-xx)^2  +  (pos(2,jj)-yy)^2 ) ;
    end
    [value_list(counter),id_list(counter)] = min(dist(counter,:));

    plot3(pos(1,id_list(counter)),pos(2,id_list(counter)),pos(3,id_list(counter)),'ro','markersize',8,'MarkerFaceColor','r')
    text(pos(1,id_list(counter)),pos(2,id_list(counter)),pos(3,id_list(counter)),num2str(counter),'Fontsize',16,'color','cyan')
    answer = questdlg('Choose another point?', ...
        'Point-wise strain', ...
        'Yes','No','Yes');
end
exportgraphics(ha,[StrainDataFolder,'point_strain.png'],'Resolution',300)

for jj = 1 : length(id_list)
    for ii = 1 : length(Eprinc)
        point_strain{jj}(ii,:) = E{ii}(id_list(jj),:);
        point_strain_princ{jj}(ii,:) = Eprinc{ii}(id_list(jj),1);
    end
end

%% Plot point strain

for ii = 1 : length(id_list)
StrainDataFolderPoint = [StrainDataFolder,'Point',num2str(ii),'\'];
mkdir(StrainDataFolderPoint)

ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(point_strain{ii}(:,1).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{x}$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolderPoint,'eps_x_p_',num2str(ii),'.png'],'Resolution',300)

ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(point_strain{ii}(:,2).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{y}$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolderPoint,'eps_y_p_',num2str(ii),'.png'],'Resolution',300)

ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(point_strain{ii}(:,3).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{xy}$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolderPoint,'eps_xy_p_',num2str(ii),'.png'],'Resolution',300)

ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(point_strain_princ{ii}(:,1).*100,'k','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{1}$, \%','Interpreter','latex')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolderPoint,'eps_1_p_',num2str(ii),'.png'],'Resolution',300)

ha = figure;
set(gcf,'Position',[100 100 1300 1000])
plot(point_strain_princ{ii}(:,1).*100,'k','LineWidth',2)
hold on
plot(point_strain{ii}(:,1).*100,'r','LineWidth',2)
plot(point_strain{ii}(:,2).*100,'g','LineWidth',2)
plot(point_strain{ii}(:,3).*100,'b','LineWidth',2)
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon$, \%','Interpreter','latex')
ylim([-1 1]*factor)

legend('$\varepsilon_1$','$\varepsilon_x$','$\varepsilon_y$','$\varepsilon_{xy}$','Location','eastoutside','Interpreter','latex')
exportgraphics(ha,[StrainDataFolderPoint,'eps_combined_p_',num2str(ii),'.png'],'Resolution',300)

close all
end

%% eps1
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
hold on
for ii = 1 : length(id_list)
    plot(point_strain_princ{ii}(:,1).*100,'LineWidth',2)
    leg{ii} = ['P',num2str(ii)];
end
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{1}$, \%','Interpreter','latex')
legend(leg,'Location','eastoutside')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_1_points.png'],'Resolution',300)

% epsx
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
hold on
for ii = 1 : length(id_list)
    plot(point_strain{ii}(:,1).*100,'LineWidth',2)
    leg{ii} = ['P',num2str(ii)];
end
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{x}$, \%','Interpreter','latex')
legend(leg,'Location','eastoutside')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_x_points.png'],'Resolution',300)

% epsy
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
hold on
for ii = 1 : length(id_list)
    plot(point_strain{ii}(:,2).*100,'LineWidth',2)
    leg{ii} = ['P',num2str(ii)];
end
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{y}$, \%','Interpreter','latex')
legend(leg,'Location','eastoutside')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_y_points.png'],'Resolution',300)

% epsxy
ha = figure;
set(gcf,'Position',[100 100 1300 1000])
hold on
for ii = 1 : length(id_list)
    plot(point_strain{ii}(:,3).*100,'LineWidth',2)
    leg{ii} = ['P',num2str(ii)];
end
xlabel('Image \#','Interpreter','latex')
ylabel('$\varepsilon_{xy}$, \%','Interpreter','latex')
legend(leg,'Location','eastoutside')
ylim([-1 1]*factor)

exportgraphics(ha,[StrainDataFolder,'eps_xy_points.png'],'Resolution',300)

close all

save([StrainDataFolder,'StrainData.mat'],'E','Eprinc','Gauge','Gauge_princ','point_strain','point_strain_princ','id_list')