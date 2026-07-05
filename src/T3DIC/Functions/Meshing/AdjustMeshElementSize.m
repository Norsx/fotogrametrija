function AdjustMeshElementSize(Mesh_geo)

fig = figure('Position',[50 50 720 720]);
ax = axes('Parent',fig);

MeshSize = 10;
fig.UserData = struct('ax', ax, 'sliderValue', MeshSize);

Mesh_gen = generateMesh(Mesh_geo,GeometricOrder="linear",Hgrad=2,Hmax=MeshSize);
Mesh.nodes = 1 : length(Mesh_gen.Mesh.Nodes);
Mesh.coordinates = [Mesh_gen.Mesh.Nodes;zeros(length(Mesh_gen.Mesh.Nodes),1)']';
Mesh.elements = 1 : length(Mesh_gen.Mesh.Elements);
Mesh.connectivity = Mesh_gen.Mesh.Elements';
% keyboard
meshViewer(Mesh)


slider = uicontrol('Style', 'slider', ...
    'Min', 2, ...
    'Max', 100, ...
    'Value', 10, ...
    'SliderStep', [0.01, 0.01], ...
    'Position', [fig.Position(3) - 200, fig.Position(4) - 30, 200, 20], ...
    'Callback', @(src, event) updateMesh(fig, src,Mesh_geo));
sliderLabel = uicontrol('Style', 'text', ...
    'String', sprintf('%.0f', fig.UserData.sliderValue), ...
    'Position', [fig.Position(3) - 230, fig.Position(4) - 30, 20, 20], ...
    'HorizontalAlignment', 'left');
fig.UserData.sliderLabel = sliderLabel;
% keyboard
button = uicontrol('Style', 'pushbutton', ...
        'String', 'Export to workspace', ...
        'Position', [10, fig.Position(4) - 70, 100, 30], ...
        'Callback', @(src, event) ExportMesh2Workspace(fig,Mesh_geo));
% keyboard

while ~evalin('base', 'exist(''Mesh'', ''var'')')
    clc
    fprintf('Waiting for the Mesh \n')
    pause(1); % Pause to prevent excessive CPU usage
end