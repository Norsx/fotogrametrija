function addHoleCallback(ax)
        if isAddingHole
            % Keep the main polygon outline visible
            set(hMainPolygonOutline, 'Visible', 'on');
            
            % Select hole type (e.g., spline)
            hole = drawSplineHole(ax);  % Function for adding a spline hole
            
            if ~isempty(hole)
                holes{end+1} = hole;  % Add hole to the list
            end
        end
    end