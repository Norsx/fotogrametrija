function exportPolygonCallback(fig)
% Retrieve data from the figure
data = guidata(fig);

if isempty(data.mainPolygon)
    errordlg('No polygon to export.');
    return;
end
% keyboard
% Create the main polygon polyshape
if isempty(fig.UserData.GF)
    % mainPoly = polyshape(data.mainPolygon.Vertices(:, 1), data.mainPolygon.Vertices(:, 2));
    mainPoly = polyshape(data.mainPolygon(:, 1), data.mainPolygon(:, 2));

else
    GF = fig.UserData.GF;
    vertices = fig.UserData.vertices;
    vertices_smoothed = GaussFilterPolygon(vertices,GF);
    mainPoly = polyshape(vertices_smoothed);
end

% Debug: Check if the main polygon is valid
if isempty(mainPoly.Vertices) || ~issimplified(mainPoly)
    errordlg('Main polygon is invalid or self-intersects.');
    disp('Main Polygon Vertices:');
    disp(data.mainPolygon);
    return;
end

% Composite polyshape for holes
compositeHoles = polyshape();

% Debugging flag
encounteredIssues = false;
partialFlag = false;
partialHole = [];
fullHole = [];
for i = 1:numel(data.holes)
    % Extract the current hole
    currentHole = data.holes{i};

    % Ensure the hole is closed
    if ~isequal(currentHole(1, :), currentHole(end, :))
        currentHole = [currentHole; currentHole(1, :)];
    end

    % Create a polyshape for the hole
    holeShape = polyshape(currentHole(:, 1), currentHole(:, 2));

    % Check if the hole is valid
    if isempty(holeShape.Vertices) || ~issimplified(holeShape)
        warning('Hole %d is invalid or self-intersects. Skipping.', i);
        encounteredIssues = true;
        continue;
    end
    % keyboard

    %% Debug points%%
    % Check if the hole is entirely inside the main polygon
    % if ~all(isinterior(mainPoly, currentHole(:, 1), currentHole(:, 2)))
    %     warning('Hole %d lies outside the main polygon. Skipping.', i);
    %     encounteredIssues = true;
    %     continue;
    % end
    if sum(unique(isinterior(mainPoly, currentHole(:, 1), currentHole(:, 2)))) == 0
        warning('Hole %d lies outside the main polygon. Skipping.', i);
        encounteredIssues = true;
        continue;
    end

    if sum(isinterior(mainPoly, currentHole(:, 1), currentHole(:, 2))) < length(currentHole(:,1))
        % warning('Hole %d partially lies outside the main polygon. \n', i);
        partialFlag = true;
        partialHole = [partialHole; i];
    else
        fullHole = [fullHole; i];
    end

    % Add the hole to the composite holes
    compositeHoles = union(compositeHoles, holeShape);
    eval(['hole',num2str(i),' = holeShape;'])
end
resultPoly = mainPoly;

if partialFlag
    for ii = 1 : numel(data.holes)

        if ismember(ii,partialHole)

            nanIdx = isnan(resultPoly.Vertices(:, 1)); % Find NaN rows
            if sum(nanIdx) > 0

                splitIndices = [0; find(nanIdx); size(resultPoly.Vertices, 1) + 1];

                for jj = 1 ...:length(splitIndices) - 1

                    startIdx = splitIndices(jj) + 1;
                    endIdx = splitIndices(jj + 1) - 1;

                    poly_temp = polyshape(resultPoly.Vertices(startIdx:endIdx, 1), resultPoly.Vertices(startIdx:endIdx, 2));

                    eval(['poly_temp = subtract(poly_temp, hole',num2str(ii),');'])

                end
                for jj = 1 : length(fullHole)

                    eval(['poly_temp = subtract(poly_temp, hole',num2str(fullHole(jj)),');'])

                end

                resultPoly = poly_temp;
                clear poly_temp
            else
                eval(['resultPoly = subtract(resultPoly, hole',num2str(ii),');'])
            end
        % keyboard
        else
            eval(['resultPoly = subtract(resultPoly, hole',num2str(ii),');'])
        end

    end
else
    % Subtract the holes from the main polygon
    resultPoly = subtract(resultPoly, compositeHoles);
end
% keyboard
% Validate the result
% if isempty(resultPoly.Vertices)
%     errordlg('The resulting polygon has no vertices. Subtraction may have failed.');
%     return;
% elseif any(isnan(resultPoly.Vertices(:)))
%     % disp('Resulting Polygon Contains NaN:');
%     % disp('Main Polygon Vertices:');
%     % disp(mainPoly.Vertices);
%     % disp('Composite Hole Vertices:');
%     % disp(compositeHoles.Vertices);
%     % disp('Resulting Polygon Vertices:');
%     % disp(resultPoly.Vertices);
%     % errordlg('The resulting polygon contains NaN vertices. Export aborted.');
%     % % return;
% end

% Debug: Warn if issues were encountered
if encounteredIssues
    msgbox('Some holes were skipped due to validation issues.', 'Warning');
end

% Export the resulting polygon to the workspace
assignin('base', 'polygonData', resultPoly);
msgbox('Polygon exported to workspace as "polygonData".');
end
