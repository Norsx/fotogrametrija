% Helper function to draw a polygon
    function polygon = drawPolygon(ax, label)
        title(ax, ['Draw ', label, ' (double-click to finish)']);

        h = drawpolygon('Parent', ax,'InteractionsAllowed','none'); % Interactive point-and-click polygon
        % keyboard
        if ~isempty(h) && isvalid(h)
            polygon = h.Position;
        else
            polygon = [];
        end

    end