function Mask = mask_from_mesh(img, Mesh)

H = size(img,1);
W = size(img,2);

mask = false(H,W);

for e = 1:size(Mesh.connectivity,1)

    % Node indices belonging to this element
    nodeIdx = Mesh.connectivity(e,:);

    % Remove invalid entries if connectivity is padded
    nodeIdx = nodeIdx(nodeIdx > 0);

    % Coordinates of element vertices
    x = Mesh.coordinates(nodeIdx,1);
    y = Mesh.coordinates(nodeIdx,2);

    % Fill element
    mask = mask | poly2mask(x,y,H,W);

end
Mask = mask;

% imshow(mask)