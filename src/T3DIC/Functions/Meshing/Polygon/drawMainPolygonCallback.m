 % Callback to draw the main polygon
    function drawMainPolygonCallback(fig, ax)
        data = guidata(fig);
        deleteAllDrawings(ax);
        data.mainPolygon = drawPolygon(ax, 'Main Polygon');
        guidata(fig, data); % Save updated data
    end