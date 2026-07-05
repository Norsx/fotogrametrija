function circle = drawCircle(ax)
    title(ax, 'Click three points to define the circle');
    [x, y] = ginput_r(3); % Select three points interactively

    % Ensure we have exactly three points
    if numel(x) ~= 3 || numel(y) ~= 3
        errordlg('You must select exactly three points.');
        circle = [];
        return;
    end

    % Calculate circle center and radius
    [center, radius] = fitCircleThroughPoints([x, y]);

    if isnan(radius) || radius <= 0
        errordlg('Invalid circle: points must not be collinear.');
        circle = [];
        return;
    end

    % Generate points around the circle
    theta = linspace(0, 2 * pi, 100);
    circleX = center(1) + radius * cos(theta);
    circleY = center(2) + radius * sin(theta);
    circle = [circleX', circleY'];

    % Plot the circle
    % keyboard
    
    limits(1,:) = ax.XLim;
    limits(2,:) = ax.YLim;
    xlim(limits(1,:))
    ylim(limits(2,:))
    hold(ax, 'on');
    plot(ax, circleX, circleY, 'r-', 'LineWidth', 2);
    plot(ax, x, y, 'b+', 'MarkerSize', 4, 'LineWidth', 2); % Plot selected points
    hold(ax, 'off');
end
