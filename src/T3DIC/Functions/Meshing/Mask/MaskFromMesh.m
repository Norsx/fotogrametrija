function Mask = MaskFromMesh(Mesh,f)

[n,m] = size(f);
boundaryVertices = extractBoundaryVertices(Mesh);

Mask = createBinaryMask(boundaryVertices, [n,m]);