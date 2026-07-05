function CreateMeshFromPolygon(p)

% Define the vertices of the irregular polygon
% xv = [1 3 5 4 2]; % x-coordinates of vertices
% yv = [1 2 1 3 4]; % y-coordinates of vertices

xv = p(:,1);
yv = p(:,2);

% Number of points you want inside the polygon (approximate)
numPoints = 50;

% Spacing for points on the edges
edgeSpacing = 80; % Adjust for tighter or looser spacing on edges

% Step 1: Generate a grid of points inside the bounding box
x_grid = linspace(min(xv), max(xv), round(sqrt(numPoints) * 2));
y_grid = linspace(min(yv), max(yv), round(sqrt(numPoints) * 2));
[X, Y] = meshgrid(x_grid, y_grid);

% Flatten the grid points
x_grid = X(:);
y_grid = Y(:);

% Filter points that are inside the polygon
in = inpolygon(x_grid, y_grid, xv, yv);
x_in = x_grid(in);
y_in = y_grid(in);

% Step 2: Generate points on the edges of the polygon
x_edge = [];
y_edge = [];
for i = 1:length(xv)
    % Define the current edge (from point i to point i+1, wrapping around)
    x1 = xv(i);
    y1 = yv(i);
    if i < length(xv)
        x2 = xv(i + 1);
        y2 = yv(i + 1);
    else
        x2 = xv(1); % Wrap around to the first vertex
        y2 = yv(1);
    end

    % Calculate distance between vertices
    edgeLength = sqrt((x2 - x1)^2 + (y2 - y1)^2);
    
    % Number of points to place along this edge
    numEdgePoints = ceil(edgeLength / edgeSpacing);
    
    % Generate points along the edge
    x_edge_i = linspace(x1, x2, numEdgePoints);
    y_edge_i = linspace(y1, y2, numEdgePoints);
    
    % Append to edge point arrays
    x_edge = [x_edge, x_edge_i];
    y_edge = [y_edge, y_edge_i];
end

% Step 3: Combine interior and edge points
x_combined = [x_in; x_edge'];
y_combined = [y_in; y_edge'];

% Optional: Plot the polygon and points
% figure;
% plot(xv, yv, 'b-', 'LineWidth', 2); % Polygon outline
% hold on;
% plot(x_combined, y_combined, '+b', 'MarkerSize', 10); % Points within and on edges
% hold off;
% axis equal;
