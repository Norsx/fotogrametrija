function X = stereoTriangulate(uv1, uv2, P1, P2)
% STEREOTRIANGULATE Linear (DLT) triangulation of points from two views.
%
%   X = stereoTriangulate(uv1, uv2, P1, P2)
%
%   uv1, uv2 : N x 2 image points [x(col), y(row)] in camera 1 / camera 2.
%   P1,  P2  : 3 x 4 camera projection matrices (x_h = P * [X;1]).
%   X        : N x 3 reconstructed world points.
%
% For each point the two views give A*[X;1] = 0 (4x4); solved by SVD null-space.

N = size(uv1,1);
X = zeros(N,3);
for i = 1:N
    A = [ uv1(i,1)*P1(3,:) - P1(1,:);
          uv1(i,2)*P1(3,:) - P1(2,:);
          uv2(i,1)*P2(3,:) - P2(1,:);
          uv2(i,2)*P2(3,:) - P2(2,:) ];
    [~,~,V] = svd(A);
    X(i,:) = V(1:3,end).' / V(4,end);
end
end
