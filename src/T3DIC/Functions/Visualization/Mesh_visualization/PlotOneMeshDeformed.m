% fig = figure('Position', [50, 50, 720, 720]);
Ux = Field(:,1);
Uy = Field(:,2);
% keyboard
deformedNodes = coor + [Ux, Uy,zeros(size(Ux))];
Magnitude = sqrt(Ux.^2 + Uy.^2);
trisurf(elements, deformedNodes(:,1), deformedNodes(:,2), Mesh.coordinates(:,3), ...
    Magnitude, 'EdgeColor', ColorEdge, 'FaceColor', ColorFace);
axis image
axis ij
view([0 0 90])