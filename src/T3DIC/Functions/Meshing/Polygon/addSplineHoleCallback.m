 % Callback to add a spline hole
    function addSplineHoleCallback(fig, ax)
        data = guidata(fig);
        if isempty(data.mainPolygon)
            errordlg('Draw the main polygon first.');
            return;
        end
        hole = drawSpline(ax);
        if ~isempty(hole)
            data.holes{end+1} = hole;
        end
        guidata(fig, data); % Save updated data
    end
