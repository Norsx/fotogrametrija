function [h, k, r] = fit_circle(x, y)
    % Fit a circle to a set of points (x, y) using least-squares method
    % Returns the center (h, k) and radius (r)
    
    % Calculate the necessary terms for fitting
    A = [x, y, ones(size(x))];
    B = x.^2 + y.^2;
    
    % Solve the normal equations: A'*A * params = A'*B
    params = (A' * A) \ (A' * B);
    
    % Extract the circle parameters
    h = 0.5 * params(1);
    k = 0.5 * params(2);
    r = sqrt(params(3) + h^2 + k^2);
end