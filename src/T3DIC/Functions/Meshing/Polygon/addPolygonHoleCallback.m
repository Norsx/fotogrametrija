% Callback to add a polygonal hole
    function addPolygonHoleCallback(fig, ax)
        data = guidata(fig);
        if isempty(data.mainPolygon)
            errordlg('Draw the main polygon first.');
            return;
        end
        hole = drawPolygon(ax, 'Polygon Hole');
        if ~isempty(hole)
            data.holes{end+1} = hole;
        end
        guidata(fig, data); % Save updated data
    end
