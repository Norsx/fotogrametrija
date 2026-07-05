%% IDEA
% Create MASK using gradients, (if needed:image erode, image dilate). After
% creating Mask, improve it by removing unwanted artifacts using polygon
% and from that polygon create an updated Mask.
% Create final polygon from MASK, use triangulation to obtain geometry and
% use fegeometry on the triangulated data to get the Mesh_geo.
% AUTOMATIC - Mask is created via gradients, image erode and dilate can be
% applied to smooth out the boundaries. Polygons is created from the mask
% and additional polygons an be used to remove artefacts or smooth out the
% boundaries of the polygon
% MANUAL - User defined the polygon over the image and adds holes manually
close all
flagMask = questdlg('How to create MASK?', ...
    'Mask generation', ...
    'Manual','Automatic','Load Mesh','Manual');

clear Mesh Mask polygonData

if strcmpi(flagMask,'Automatic')
    CreateMaskFromImage(f);

    %%
    drawPolygonWithHoles(Mask,f,flagMask)
elseif strcmpi(flagMask,'Load Mesh')
    [file,location] = uigetfile('*.mat');
    load([location,file],'Mesh')
% keyboard
    if ~isfield(Mesh,'Mask')
        % keyboard
        if size(Mesh.connectivity,2) == 4
            Mesh.connectivity(:,1) = [];
        end
        if ~isfield(Mesh,'MeshSize')
            Mesh.MeshSize = 0;
        end
        Mask = mask_from_mesh(f,Mesh);
    else
        Mask = Mesh.Mask;
    end

else
    drawPolygonWithHoles(f,f,flagMask)
end
if ~strcmpi(flagMask,'Load Mesh')
    Mask = createBinaryMask(polygonData.Vertices, [n,m]);
    figure;imagesc(Mask);axis image;hold on; plot(polygonData)

    figure;
    imagesc(Mask);axis image
    colormap gray
    hold on
    plot(polygonData)

    tr = triangulation(polygonData);
    % figure;
    % triplot(tr)

    Mesh_geo= fegeometry(tr);

    AdjustMeshElementSize(Mesh_geo)
    if strcmpi(flagMask,'Automatic')
        [Mesh.coordinates, Mesh.connectivity] = MeshRemoveSmallElements(Mesh.coordinates, Mesh.connectivity, 30);
    end
    Mesh.nodes = [1 : length(Mesh.coordinates)]';
    Mesh.elements = [1 : length(Mesh.connectivity)]';
    Mesh = MeshCheckUpsideDown(Mesh);
    Mesh.Mask = Mask;
    save([SaveFolder,'Mesh.mat'],'Mesh','Mask','Mesh_geo','polygonData')

end
close all
PlotMesh(Mesh)