% Outer boundary (a square)
outerBoundaryX = [0, 10, 10, 0, 0];
outerBoundaryY = [0, 0, 10, 10, 0];

% Hole boundary (a smaller square inside)
holeX = [4, 6, 6, 4, 4];
holeY = [4, 4, 6, 6, 4];

% Combine vertices (outer + hole)
vertices = [outerBoundaryX', outerBoundaryY'; holeX', holeY'];

% Define edges for the constraints
outerEdges = [(1:4)', (2:5)'];  % Outer boundary edges
holeEdges = [(5:8)', (6:9)'];   % Hole edges

% Combine edges
edges = [outerEdges; holeEdges];

% Perform constrained Delaunay triangulation
DT = delaunayTriangulation(vertices, edges);

% Identify triangles whose centroids are inside the hole
% Calculate centroids of all triangles
triCentroids = incenter(DT); % Centroids of triangles

% Check if these centroids lie inside the hole
[inHole, ~] = inpolygon(triCentroids(:,1), triCentroids(:,2), holeX, holeY);

% Remove triangles whose centroids are inside the hole
trianglesToKeep = ~inHole;

% Keep only valid triangles
triangulationWithHole = DT.ConnectivityList(trianglesToKeep, :);

% Ensure the triangulation isn't empty
if isempty(triangulationWithHole)
    error('The resulting triangulation is empty. Check your constraints and geometry.');
end

% Plot the triangulation
figure;
triplot(triangulationWithHole, DT.Points(:,1), DT.Points(:,2));
hold on;

% Highlight the outer boundary and the hole
plot(outerBoundaryX, outerBoundaryY, 'r-', 'LineWidth', 2);  % Outer boundary
plot(holeX, holeY, 'b-', 'LineWidth', 2);                   % Hole boundary
axis equal;
title('Delaunay Triangulation with Hole');
