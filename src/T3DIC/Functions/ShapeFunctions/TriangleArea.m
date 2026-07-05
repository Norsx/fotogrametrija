function A = TriangleArea(p)
% keyboard
% Coordinates of the vertices
x1 = p(1,1); y1 = p(1,2);
x2 = p(2,1); y2 = p(2,2);
x3 = p(3,1); y3 = p(3,2);

% Calculate the area
A = 0.5 *abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

% Display the result
% fprintf('The area of the triangle is %.2f\n', area);