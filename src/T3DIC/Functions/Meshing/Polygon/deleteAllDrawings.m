  % Helper function to delete all drawings
    function deleteAllDrawings(ax)
        delete(findall(ax, 'Type', 'images.roi.Polygon'));
        delete(findall(ax, 'Type', 'images.roi.Circle'));
        delete(findall(ax, 'Type', 'images.roi.Polyline'));
    end