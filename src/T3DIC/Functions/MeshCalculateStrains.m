function E = MeshCalculateStrains(Mesh,U,varargin)
% Necessary inputs: MESH, DISPLACEMENT FIELDS U
% OPTIONAL INPUTS:
% E = MeshCalculateStrains(Mesh,U,'NodeExtrap',1); returns the strain
% fields in the nodes
% E = MeshCalculateStrains(Mesh,U,'Principal',1); returns the principal
% strains in the nodes. NodeExtrap is automatically assumed.




numElements = size(Mesh.connectivity, 1);
numNodes = length(Mesh.nodes);

conn = Mesh.connectivity;
coor = Mesh.coordinates;
% Npx = Mesh.Npx;
% X = Mesh.X;
% Y = Mesh.Y;
im_num = length(U);

NodeExtrap = find(strcmp(varargin,'NodeExtrap'));
if NodeExtrap ~= 0
    FlagNodeExtrap = varargin{NodeExtrap+1};
else
    FlagNodeExtrap = 0;
end

Principal = find(strcmp(varargin,'Principal'));
if Principal ~= 0
    FlagPrincipal = varargin{Principal+1};
    FlagNodeExtrap = 1;
else
    FlagPrincipal = 0;
end

% keyboard
for im = 1 : im_num
    % keyboard
    strainField{im} = zeros(numElements, 3);
    % Initialize arrays for nodal strain extrapolation
    if FlagNodeExtrap
        nodalStrainsSum{im} = zeros(numNodes, 3); % Sum of strains at each node
        nodalStrainCount{im} = zeros(numNodes, 1); % Number of contributing elements for each node
    end
    for e = 1:numElements
        % Get node indices for the current element
        nodes = conn(e, :);

        % Coordinates of the element nodes
        x = coor(nodes, 1);
        y = coor(nodes, 2);

        % Displacements of the element nodes
        ux = U{im}(nodes, 1);
        uy = U{im}(nodes, 2);
        d = [ux(1); uy(1); ux(2); uy(2); ux(3); uy(3)];

        % Compute shape function derivatives
        A = det([1, x(1), y(1); 1, x(2), y(2); 1, x(3), y(3)]) / 2;
        b = [(y(2) - y(3)), (y(3) - y(1)), (y(1) - y(2))] / (2 * A);
        c = [(x(3) - x(2)), (x(1) - x(3)), (x(2) - x(1))] / (2 * A);

        % Construct B matrix
        B = [b(1), 0, b(2), 0, b(3), 0;
            0, c(1), 0, c(2), 0, c(3);
            c(1), b(1), c(2), b(2), c(3), b(3)];

        % Compute strains for the element
        strain = B * d;

        % Store strain components [exx, eyy, exy]
        strainField{im}(e, :) = [strain(1), strain(2), strain(3)];

        if FlagNodeExtrap
            % Extrapolate to nodes (distribute element strain to its nodes)
            for i = 1:3
                nodalStrainsSum{im}(nodes(i), :) = nodalStrainsSum{im}(nodes(i), :) + strainField{im}(e, :);
                nodalStrainCount{im}(nodes(i)) = nodalStrainCount{im}(nodes(i)) + 1;
            end
            nodalStrains{im} = nodalStrainsSum{im} ./ nodalStrainCount{im};
        end
    end
end
% keyboard
if FlagPrincipal 
    for ii = 1 : im_num
        for jj = 1 : numNodes
            eps_xx = nodalStrains{ii}(jj,1);
            eps_yy = nodalStrains{ii}(jj,2);
            eps_xy = nodalStrains{ii}(jj,3);

            Eprinc{ii}(jj,1) = 0.5*(eps_xx + eps_yy + sqrt((eps_xx - eps_yy).^2 ...
                + 4*eps_xy.^2));
            Eprinc{ii}(jj,2) = 0.5*(eps_xx + eps_yy - sqrt((eps_xx - eps_yy).^2 ...
                + 4*eps_xy.^2));
            Eprinc{ii}(jj,3) = 0;

        end
    end
end
% keyboard
if FlagNodeExtrap && FlagPrincipal == 0
    E = nodalStrains;
elseif FlagPrincipal
    E = Eprinc;
else
    E = strainField;
end

% keyboard
