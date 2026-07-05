function updateMesh(fig, src, Mesh_geo)
% keyboard
fig.UserData.sliderLabel.String = sprintf('%.0f', round(src.Value));
fig.UserData.sliderValue = round(src.Value);

Mesh_gen = generateMesh(Mesh_geo,GeometricOrder="linear",Hgrad=2,Hmax=src.Value);
Mesh.nodes = 1 : length(Mesh_gen.Mesh.Nodes);
Mesh.coordinates = [Mesh_gen.Mesh.Nodes;zeros(length(Mesh_gen.Mesh.Nodes),1)']';
Mesh.elements = 1 : length(Mesh_gen.Mesh.Elements);
Mesh.connectivity = Mesh_gen.Mesh.Elements';

meshViewer(Mesh)