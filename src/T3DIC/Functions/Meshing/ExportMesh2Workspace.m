function ExportMesh2Workspace(fig,Mesh_geo)

% keyboard
MeshSize = fig.UserData.sliderValue;

Mesh_gen = generateMesh(Mesh_geo,GeometricOrder="linear",Hgrad=2,Hmax=MeshSize);
Mesh.nodes = 1 : length(Mesh_gen.Mesh.Nodes);
Mesh.coordinates = [Mesh_gen.Mesh.Nodes;zeros(length(Mesh_gen.Mesh.Nodes),1)']';
Mesh.elements = 1 : length(Mesh_gen.Mesh.Elements);
Mesh.connectivity = Mesh_gen.Mesh.Elements';
Mesh.MeshSize = MeshSize;
assignin('base', 'Mesh', Mesh);