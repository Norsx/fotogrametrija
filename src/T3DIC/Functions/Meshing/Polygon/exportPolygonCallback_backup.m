 % Callback to export the polygon
    function exportPolygonCallback_backup(fig)
        data = guidata(fig);
        if isempty(data.mainPolygon)
            errordlg('No polygon to export.');
            return;
        end
        % keyboard
        % Create polyshape object
        poly = polyshape(data.mainPolygon(:, 1), data.mainPolygon(:, 2));
        for i = 1:numel(data.holes)
            poly = addboundary(poly, data.holes{i}(:, 1), data.holes{i}(:, 2));
        end

        % Export to workspace
        assignin('base', 'polygonData', poly);
        msgbox('Polygon exported to workspace as "polygonData".');
    end