function [filteredTriangulation] = FilterTriangulation(points,DT)
% keyboard

num_points = length(points);
Vertices = [1:num_points]';

for ii = 1 : num_points-1
    % 
    % if ii == num_points
    %     EdgeVertices(ii,1) = Vertices(ii);
    %     EdgeVertices(ii,2) = Vertices(1);
    % else
        edges(ii,1) = Vertices(ii);
        edges(ii,2) = Vertices(ii+1);
    % end
end

polygon = polyshape(points(:,1), points(:,2));

% Find the centroids of each triangle in the triangulation
triangles = DT.ConnectivityList;
centroids = mean(reshape(points(triangles', :), [3, size(triangles, 1), 2]), 1);

% Check if the centroids of each triangle are inside the polygon
isInside = isinterior(polygon, centroids(:,:,1), centroids(:,:,2));

% Filter triangles that are inside the polygon
validTriangles = triangles(isInside, :);

% Create a new triangulation object with filtered triangles
filteredTriangulation = triangulation(validTriangles, points);

return
figure;
hold on;
triplot(filteredTriangulation, 'Color', 'blue');
plot(points(:,1), points(:,2), 'ro', 'MarkerSize', 8, 'LineWidth', 1.5);
plot(polygon, 'FaceColor', 'none', 'EdgeColor', 'k', 'LineWidth', 1.5);
title('Filtered Delaunay Triangulation (Updated Connectivity List)');
hold off;
