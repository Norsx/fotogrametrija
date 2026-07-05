function [vertices, elements] = createFEMeshFromBinaryMaskWithHoles(binaryMask, maxElementSize)
    % CREATEFEMESHFROMBINARYMASKWITHHOLES Generates a finite element mesh
    % from a binary mask with holes.
    %
    % Inputs:
    %   binaryMask      - A logical matrix where 'true' represents the region of interest.
    %   maxElementSize  - Maximum size of finite elements.
    %
    % Outputs:
    %   vertices        - Nx2 matrix of vertex coordinates [x, y].
    %   elements        - Mx3 matrix of triangular elements (indices into vertices).
    %
    % Example:
    %   binaryMask = false(100, 100);
    %   binaryMask(20:80, 20:80) = true;
    %   binaryMask(40:60, 40:60) = false;
    %   [vertices, elements] = createFEMeshFromBinaryMaskWithHoles(binaryMask, 5);
    %   triplot(elements, vertices(:,1), vertices(:,2));
    
    % Validate inputs
    if ~islogical(binaryMask)
        error('Input binaryMask must be a logical matrix.');
    end
    keyboard
    % Extract boundaries of all regions (outer and holes)
    boundaries = bwboundaries(binaryMask, 'holes');
    
    % Create polyshape for the main region and holes
    mainBoundary = boundaries{1}; % First boundary is the outer boundary
    poly = polyshape(mainBoundary(:, 2), mainBoundary(:, 1)); % (x, y) = (column, row)
    
    % Add holes to the polyshape
    for i = 2:numel(boundaries)
        holeBoundary = boundaries{i};
        holeShape = polyshape(holeBoundary(:, 2), holeBoundary(:, 1)); % (x, y) = (column, row)
        poly = subtract(poly, holeShape); % Subtract hole from the main region
    end
    
    % Visualize the polygon with holes
    figure;
    plot(poly);
    title('Polygon with Holes');
    axis equal;

    % Check if the polyshape is empty (e.g., invalid mask)
    if isempty(poly.Vertices)
        error('The resulting polygon is empty. Check the binary mask.');
    end

    % Set up a PDE model
    model = createpde;

    % Include the geometry in the model
    [x, y] = boundary(poly); % Get boundary coordinates
    geometryFromEdges(model, poly);

    % Generate the mesh
    generateMesh(model, 'GeometricOrder', 'linear', 'Hmax', maxElementSize);

    % Extract mesh data
    nodes = model.Mesh.Nodes; % Node coordinates
    elements = model.Mesh.Elements; % Element connectivity

    % Convert to output format
    vertices = nodes';
    elements = elements';

    % Visualize the finite element mesh
    figure;
    pdemesh(model);
    title('Finite Element Mesh');
    axis equal;
end
