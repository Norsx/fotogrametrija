function [psi,N] = CalcT3MeshShapeFun_old(p,X,Y,Mask)
% Wiki link to barycentric coordinates:
% https://en.wikipedia.org/wiki/Barycentric_coordinate_system

p1 = p(1,:);
p2 = p(2,:);
p3 = p(3,:);

% Define the coordinates of the triangle vertices in pixel coordinates
% A = p1;   % Vertex A in pixels
% B = p2;   % Vertex B in pixels
% C = p3;   % Vertex C in pixels
% 
% % Define a set of pixel points you want to analyze
% P = [X(Mask),Y(Mask)]; % Example points, replace with actual points
% 
% % Calculate vectors AB and AC (they remain the same for all points)
% v0 = B - A;
% v1 = C - A;
% 
% % Calculate dot products that are constant across all points
% dot00 = dot(v0, v0);
% dot01 = dot(v0, v1);
% dot11 = dot(v1, v1);
% denom = dot00 * dot11 - dot01 * dot01;
% 
% % Calculate the barycentric coordinates for each point in P
% v2 = P - A; % AP vector for all points in P
% 
% % Dot products for barycentric coordinates
% dot02 = sum(v2 .* v0, 2); % Dot product of each AP with AB
% dot12 = sum(v2 .* v1, 2); % Dot product of each AP with AC
% 
% % Calculate barycentric coordinates (shape functions)
% lambda1 = (dot11 * dot02 - dot01 * dot12) / denom; % N1 for A
% lambda2 = (dot00 * dot12 - dot01 * dot02) / denom; % N2 for B
% lambda3 = 1 - lambda1 - lambda2;                   % N3 for C
% 
% Npx = length(X(Mask));


%% comment
A  = TriangleArea(p1,p2,p3);

centroid = FindTriangleCentroid(p);
x1 = p1(1,1);
y1 = p1(1,2);
x2 = p2(1,1);
y2 = p2(1,2);
x3 = p3(1,1);
y3 = p3(1,2);

L1 = sqrt((x2 - x3)^2 + (y2 - y3)^2);
L2 = sqrt((x1 - x3)^2 + (y1 - y3)^2);
L3 = sqrt((x2 - x1)^2 + (y2 - y1)^2);
keyboard

A1 = TriangleArea(p1,p2,centroid);
A2 = TriangleArea(p1,centroid,p3);
A3 = TriangleArea(centroid,p2,p3);


% keyboard
flag = 1;
switch flag
    case 1

    case 2

        x1 = p1(1,1)/sqrt(A);
        y1 = p1(1,2)/sqrt(A);
        x2 = p2(1,1)/sqrt(A);
        y2 = p2(1,2)/sqrt(A);
        x3 = p3(1,1)/sqrt(A);
        y3 = p3(1,2)/sqrt(A);
        for ii = 1 : 3
            eval(['p',num2str(ii),'_norm(1,1) = x',num2str(ii),';'])
            eval(['p',num2str(ii),'_norm(1,2) = y',num2str(ii),';'])
        end
        A  = TriangleArea(p1_norm,p2_norm,p3_norm);
    case 3
        % keyboard
        x1 = p1(1,1)/L1;
        y1 = p1(1,2)/L1;
        x2 = p2(1,1)/L2;
        y2 = p2(1,2)/L2;
        x3 = p3(1,1)/L3;
        y3 = p3(1,2)/L3;
        for ii = 1 : 3
            eval(['p',num2str(ii),'_norm(1,1) = x',num2str(ii),';'])
            eval(['p',num2str(ii),'_norm(1,2) = y',num2str(ii),';'])
        end
        A  = TriangleArea(p1_norm,p2_norm,p3_norm);
    case 4 
        % centroid area used as normalization
end
% keyboard
N(:,1) = 0.5*A*(x2*y3 - x3*y2 + (y2 - y3)*X(Mask) + (x3 - x2)*Y(Mask));
N(:,2) = 0.5*A*(x3*y1 - x1*y3 + (y3 - y1)*X(Mask) + (x1 - x3)*Y(Mask));
N(:,3) = 0.5*A*(x1*y2 - x2*y1 + (y1 - y2)*X(Mask) + (x2 - x1)*Y(Mask));

%% comment

% N(:,1) = lambda1;
% N(:,2) = lambda2;
% N(:,3) = lambda3;
ndof = 6;
Npx = length(X(Mask));
psi = zeros(Npx,ndof,2);
psi(:,1:2:ndof,1) = N;
psi(:,2:2:ndof,2) = N;
