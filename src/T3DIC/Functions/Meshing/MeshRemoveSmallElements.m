function [filtered_nodes, filtered_elements] = MeshRemoveSmallElements(nodes, elements, min_area_threshold)
% remove_small_elements_with_unused_nodes
% Removes small elements from a 2D T3 mesh and cleans up unused nodes.
%
% Inputs:
%   nodes              - Nx2 array of node coordinates
%   elements           - Mx3 array of triangular element connectivity (node indices)
%   min_area_threshold - Minimum allowable area for triangles
%
% Outputs:
%   filtered_nodes     - Filtered node coordinates
%   filtered_elements  - Mx3 array of triangular elements with small ones removed

% Preallocate areas array
areas = zeros(size(elements, 1), 1);
% keyboard
% Calculate the area of each triangular element
for i = 1:size(elements, 1)
    % Extract vertices of the triangle
    v = nodes(elements(i,:), :); % Get the 3 vertices of the triangle
    % Compute area using the determinant method
    areas(i) = 0.5 * abs(det([v(1,1:2) 1; v(2,1:2) 1; v(3,1:2) 1]));
end

% Identify elements with area greater than or equal to the threshold
large_elements = areas >= min_area_threshold;

% Filter elements
filtered_elements = elements(large_elements, :);

% Find unique nodes still in use
used_node_indices = unique(filtered_elements(:));

% Map old node indices to new ones
new_index_map = zeros(size(nodes, 1), 1); % Map from old to new indices
new_index_map(used_node_indices) = 1:length(used_node_indices);

% Remap the elements to the new node indices
filtered_elements = new_index_map(filtered_elements);

% Keep only the used nodes
filtered_nodes = nodes(used_node_indices, :);

% Display information about removed elements and nodes
fprintf('Original number of elements: %d\n', size(elements, 1));
fprintf('Number of elements after filtering: %d\n', size(filtered_elements, 1));
fprintf('Number of elements removed: %d\n', size(elements, 1) - size(filtered_elements, 1));
fprintf('Original number of nodes: %d\n', size(nodes, 1));
fprintf('Number of nodes after filtering: %d\n', size(filtered_nodes, 1));
fprintf('Number of nodes removed: %d\n', size(nodes, 1) - size(filtered_nodes, 1));


end
