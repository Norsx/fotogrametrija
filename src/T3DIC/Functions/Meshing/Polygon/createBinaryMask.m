function binaryMask = createBinaryMask(polygon, imageSize)
    % Inputs:
    % polygon - Nx2 array containing [x, y] vertices of the polygon (with NaNs)
    % imageSize - [height, width] of the binary mask
% keyboard
    % Validate inputs
    if isempty(polygon) || size(polygon, 2) ~= 2
        error('Polygon must be a non-empty Nx2 array of [x, y] coordinates.');
    end

    if numel(imageSize) ~= 2
        error('imageSize must be a two-element vector [height, width].');
    end

    % Initialize the binary mask
    binaryMask = false(imageSize);

    % keyboard
    % Split the polygon into parts based on NaN values
    nanIdx = isnan(polygon(:, 1)); % Find NaN rows
    splitIndices = [0; find(nanIdx); size(polygon, 1) + 1]; % Indices separating parts

    % Process each sub-polygon separately
    for i = 1:length(splitIndices) - 1
        startIdx = splitIndices(i) + 1;
        endIdx = splitIndices(i + 1) - 1;

        if startIdx <= endIdx
            % Extract current sub-polygon
            subPolygon = polygon(startIdx:endIdx, :);

            % Skip empty or invalid sub-polygons
            if isempty(subPolygon) || size(subPolygon, 1) < 3
                continue;
            end

            % Generate mask for this sub-polygon and combine
            xCoords = subPolygon(:, 1);
            yCoords = subPolygon(:, 2);
            subMask = poly2mask(xCoords, yCoords, imageSize(1), imageSize(2));
        end

        if i ~= 1
            binaryMask = binaryMask & ~subMask;
        else
            binaryMask = binaryMask | subMask; % Combine masks
        end
    end

    % % Visualize the mask (optional)
    % figure;
    % imshow(binaryMask);
    % title('Binary Mask of the Polygon');
end
