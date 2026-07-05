function Mesh = MeshCheckUpsideDown(Mesh)
    % fix_flipped_elements
    % This function checks for upside-down (flipped) or inside-out elements 
    % and fixes them by reversing the order of nodes if necessary.
    %
    % Inputs:
    %   Mesh.nodes     - Nx2 array of node coordinates
    %   Mesh.elements  - Mx3 array of triangular element connectivity (node indices)
    %   Mesh.coordinates - (same as Mesh.nodes)
    %   Mesh.connectivity - (same as Mesh.elements)
    %
    % Outputs:
    %   Mesh           - Updated Mesh structure with fixed element orientations
    
    % Loop through each element and check its orientation
    conn = Mesh.connectivity;
    coor = Mesh.coordinates;

    for i = 1:size(conn, 1)
        % Get the node indices for the current element (triangle)
        element_nodes = coor(conn(i,:), :);
        
        % Calculate the signed area of the triangle to check the orientation
        area = 0.5 * abs(det([element_nodes(1,1:2), 1; element_nodes(2,1:2), 1; element_nodes(3,1:2), 1]));
        
        % If the area is negative, the element is flipped
        if area < 0
            % Flip the element by reversing the order of nodes
            conn(i,:) = conn(i,[3, 2, 1]);
        end
    end
    
    % Update the connectivity and coordinates based on fixed elements
    Mesh.connectivity = conn;
    Mesh.coordinates = coor;
    
    % Display a message indicating how many elements were flipped
    flipped_count = sum(area < 0);
    fprintf('%d elements were flipped and corrected.\n', flipped_count);
end
