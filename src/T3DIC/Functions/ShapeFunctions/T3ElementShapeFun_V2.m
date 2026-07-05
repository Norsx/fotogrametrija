function [psi_x,psi_y, vec] = T3ElementShapeFun_V2(coor,X,Y)

ndof = 3*2;
N = zeros(length(X(:)),3);
% vec = zeros()
% keyboard
P1 = coor(1,1:2);   % Vertex A in pixels
P2 = coor(2,1:2);   % Vertex B in pixels
P3 = coor(3,1:2);   % Vertex C in pixels

XX = [P1; P2; P3]';  % 2P3(1,1) matrix, each column is a vertex

% Unit triangle vertices
Xi = [0 1 0];  % Unit triangle x-coordinates
Eta = [0 0 1]; % Unit triangle y-coordinates

% Construct the system for T and b
A = [XX; 1, 1, 1];
B = [Xi; Eta; 1, 1, 1];
Transform = B / A;
T = Transform(1:2, 1:2);  % Transformation matrix
b = Transform(1:2, 3);    % Translation vector

% Define a global point
P_global = [Y(:), X(:)];  

% Map to normalized coordinates
P_normalized = T * P_global' + b;
xi = P_normalized(1,:)';
eta = P_normalized(2, :)';
% keyboard
% Shape functions in normalized space
N(:,1) = 1 - xi - eta;
N(:,2) = xi;
N(:,3) = eta;
Mask = (N(:,1) >= 0 & N(:,1) <= 1) & (N(:,2) >= 0 & N(:,2) <= 1) & (N(:,3) >= 0 & N(:,3) <= 1);
Npx = sum(Mask(:));
% keyboard
vec = zeros(Npx,2);
vec(:,1) = X(Mask);
vec(:,2) = Y(Mask);
% keyboard

psi_x = sparse(Npx,ndof);
psi_y = sparse(Npx,ndof);

psi_x(:,1:2:ndof) = N(Mask,:);
psi_y(:,2:2:ndof) = N(Mask,:);
