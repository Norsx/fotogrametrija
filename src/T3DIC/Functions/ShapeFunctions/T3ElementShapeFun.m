function psi = T3ElementShapeFun(coor,n_id,X,Y,Mask)
% keyboard
% Define the coordinates of the triangle vertices in pixel coordinates
A = coor(n_id(1),1:2);   % Vertex A in pixels
B = coor(n_id(2),1:2);   % Vertex B in pixels
C = coor(n_id(3),1:2);   % Vertex C in pixels


% % Define a set of pixel points you want to analyze
P = [X(Mask),Y(Mask)]; % Example points, replace with actual points

% Calculate vectors AB and AC (they remain the same for all points)
v0 = B - A;
v1 = C - A;

% Calculate dot products that are constant across all points
dot00 = dot(v0, v0);
dot01 = dot(v0, v1);
dot11 = dot(v1, v1);
denom = dot00 * dot11 - dot01 * dot01;

% Calculate the barycentric coordinates for each point in P
v2 = P - A; % AP vector for all points in P

% Dot products for barycentric coordinates
dot02 = sum(v2 .* v0, 2); % Dot product of each AP with AB
dot12 = sum(v2 .* v1, 2); % Dot product of each AP with AC

% Calculate barycentric coordinates (shape functions)
N(:,1) = (dot11 * dot02 - dot01 * dot12) / denom; % N1 for A
N(:,2) = (dot00 * dot12 - dot01 * dot02) / denom; % N2 for B
N(:,3) = 1 - N(:,1) - N(:,2);                   % N3 for C

Npx = length(X(Mask));
ndof = length(n_id)*2;
psi = zeros(Npx,ndof,2);
psi(:,1:2:ndof,1) = N;
psi(:,2:2:ndof,2) = N;