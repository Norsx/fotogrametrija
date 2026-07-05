function splineHole = drawSpline(ax)
    % Hide the cursor during input (set to watch cursor)
    set(gcf, 'Pointer', 'watch');

    % Lock the plot to prevent user interaction with the polygon
    set(ax, 'XLimMode', 'manual', 'YLimMode', 'manual'); % Fix the axis limits
    axis(ax, 'on'); % Turn off interactive zoom/pan

    title(ax, 'Click points to define the spline hole (right-click to finish)');

    % Initialize arrays to store the points
    xPoints = [];
    yPoints = [];
    
    % Collect points interactively (right-click to finish)
    while true
        [x, y, button] = ginput_r(1);  % Collect one point at a time
        if button == 3  % Right-click ends the point collection
            break;
        end
        
        % Add point to arrays
        xPoints = [xPoints; x];
        yPoints = [yPoints; y];
        
        % Plot the new point immediately
        hold(ax, 'on');
        plot(ax, xPoints, yPoints, 'r+', 'MarkerSize', 4, 'LineWidth', 1); 
        hold(ax, 'off');
    end

    % Ensure at least 3 points are selected
    if length(xPoints) < 3
        errordlg('You must select at least 3 points for a valid spline hole.');
        splineHole = [];
        return;
    end

    % Close the spline by adding the first point to the end
    xPoints = [xPoints; xPoints(1)];
    yPoints = [yPoints; yPoints(1)];

    % Ensure the spline passes through the selected points
    % Use 'pchip' (Piecewise Cubic Hermite Interpolating Polynomial) to pass through the points
    t = 1:length(xPoints); % Define a parameter for the spline
    ppX = pchip(t, xPoints); % Piecewise cubic interpolation for x
    ppY = pchip(t, yPoints); % Piecewise cubic interpolation for y

    % Generate points along the spline (100 points for smoothness)
    tFine = linspace(1, length(xPoints), 100); % Interpolated points
    splineX = ppval(ppX, tFine);  % Interpolated x coordinates
    splineY = ppval(ppY, tFine);  % Interpolated y coordinates

    % Plot the spline hole
    hold(ax, 'on');
    plot(ax, splineX, splineY, 'g-', 'LineWidth', 2);  % Plot spline curve in green
    plot(ax, xPoints(1:end-1), yPoints(1:end-1), 'bo', 'MarkerSize', 8, 'LineWidth', 2); % Plot control points (without last duplicate)
    hold(ax, 'off');

    % Return the spline points as output
    splineHole = [splineX(:), splineY(:)];

    % Restore the default cursor and axis interaction
    set(gcf, 'Pointer', 'arrow');
    axis(ax, 'on'); % Restore the axis to allow interaction again
end
