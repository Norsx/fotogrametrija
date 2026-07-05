function [virtgauge,Agauge] = Define_virtual_gauge(E,inc,ResultsFolder,Mesh)
% keyboard

coor = Mesh.coordinates;

A = MeshArea(Mesh);

ha = figure;
set(gcf,'Position',[100 100 1300 720])
%     imagesc(frgb)
set(gcf,'color','w');
set(gca,'XColor', 'none','YColor','none')
PlotMesh(Mesh,'Field',E{inc}(:,1));
% title(sprintf('E1 (inc: %d)',inc))
axis image
colormap (hot);
colorbar
set(gca,'FontName','Times New Roman','Fontsize',26,'linewidth',2);
clim([0 0.1])
hold on
[x, y] = ginput(2);

gaugepos = [mean(x) mean(y)];
gaugeheight = abs([y(2,1)-y(1,1)]);    % [px] normal
gaugewidth  = abs([x(2,1)-x(1,1)]);    % [px] normal

gaugex = gaugepos(1) + 0.5*gaugewidth(1)*[-1, 1, 1, -1];
gaugey = gaugepos(2) + 0.5*gaugeheight(1)*[-1, -1, 1, 1];
patch(gaugex,gaugey,1,'FaceColor','none','EdgeColor','b','linewidth',2);

virtgauge = find( (abs(coor(:,1)-gaugepos(1)) <= 0.5*gaugewidth(1)) & (abs(coor(:,2)-gaugepos(2)) <= 0.5*gaugeheight(1)) );
hold on
% set(94,'CurrentAxes');hold on
plot(coor(virtgauge,1),coor(virtgauge,2),'.b','linewidth',2,'markersize',18);
% set(94,'CurrentAxes');hold on
plot(coor(virtgauge,1),coor(virtgauge,2),'.b','linewidth',2,'markersize',18);
drawnow
print(ha,strcat(ResultsFolder,'VirtualGauge'),'-dpng')
% keyboard
%%
ha = figure;
set(gcf,'Position',[100 100 1300 720])
%     imagesc(frgb)
set(gcf,'color','w');
set(gca,'XColor', 'none','YColor','none')
PlotMesh(Mesh)
axis image
hold on
plot(coor(virtgauge,1),coor(virtgauge,2),'.','Color','r','linewidth',2,'markersize',24);
print(ha,strcat(ResultsFolder,'VirtualGauge_mesh'),'-dpng')

close all

Agauge = sum(A(virtgauge,:));
end