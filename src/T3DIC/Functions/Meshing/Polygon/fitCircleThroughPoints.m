function [center, radius] = fitCircleThroughPoints(points)
    % Fit a circle through three points
    % points: a 3x2 matrix where each row is a [x, y] coordinate
    
    % Extract the points
    x1 = points(1, 1); y1 = points(1, 2);
    x2 = points(2, 1); y2 = points(2, 2);
    x3 = points(3, 1); y3 = points(3, 2);

    % Calculate the determinants
    A = x1 * (y2 - y3) - y1 * (x2 - x3) + (x2 * y3 - x3 * y2);

    if abs(A) < 1e-10
        % Points are collinear or nearly collinear
        center = [NaN, NaN];
        radius = NaN;
        return;
    end

    B = (x1^2 + y1^2) * (y3 - y2) + ...
        (x2^2 + y2^2) * (y1 - y3) + ...
        (x3^2 + y3^2) * (y2 - y1);

    C = (x1^2 + y1^2) * (x2 - x3) + ...
        (x2^2 + y2^2) * (x3 - x1) + ...
        (x3^2 + y3^2) * (x1 - x2);

    D = (x1^2 + y1^2) * (x3 * y2 - x2 * y3) + ...
        (x2^2 + y2^2) * (x1 * y3 - x3 * y1) + ...
        (x3^2 + y3^2) * (x2 * y1 - x1 * y2);

    % Calculate the center
    centerX = -B / (2 * A);
    centerY = -C / (2 * A);
    center = [centerX, centerY];

    % Calculate the radius
    radius = sqrt((centerX - x1)^2 + (centerY - y1)^2);
end
