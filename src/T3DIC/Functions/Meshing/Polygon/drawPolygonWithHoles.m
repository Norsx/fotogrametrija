function drawPolygonWithHoles(f,img,flagMask)
% Create a figure for the UI
fig = figure('Name', 'Draw Polygon with Holes', 'NumberTitle', 'off', ...
    'MenuBar', 'none', 'ToolBar', 'none', 'Position', [100, 100, 800, 600]);
% keyboard
if strcmpi(flagMask,'Automatic')
res = zeros(size(img));
res(f) = img(f);
% Load and display an image
ax = axes('Parent', fig, 'Position', [0.1 0.2 0.8 0.75]);
GF = 2;
% keyboard
boundaries = bwboundaries(f,'noholes');

% Initialize the cell array for polygons
polygons = cell(size(boundaries));
% Convert each boundary to a polygon
for k = 1:length(boundaries)
    boundary = boundaries{k}; % Boundary coordinates
    polygons{k} = boundary(:, [2, 1]); % Switch to [x, y] format
end
polyg = polyshape(polygons{1}(:,1),polygons{1}(:,2));

vertices = polyg.Vertices;
nanIdx = isnan(vertices(:, 1));

splitIndices = [0; find(nanIdx); size(vertices, 1) + 1];
vertices(splitIndices(2):end,:) = [];
vertices_smoothed = GaussFilterPolygon(vertices,GF);
simplifiedPoly = reducepoly(vertices_smoothed,0.0005);
poly_new = polyshape(simplifiedPoly);
DisplayPolyOverMask(poly_new,res)
title('Mask + approx. POLYGON')
% keyboard
% Initialize shared data
data.mainPolygon = poly_new; % change to empty if not wanting a polygon
data.holes = {};
guidata(fig, data); % Store data in the figure
fig.UserData.vertices = vertices;
fig.UserData.GF = GF;
else
data.mainPolygon = [];
data.holes = {};
fig.UserData.GF = [];
guidata(fig, data);
ax = axes('Parent', fig, 'Position', [0.1 0.2 0.8 0.75]);
imagesc(f);axis image; colormap gray

end
% keyboard
% Add buttons
if ~isempty(data.mainPolygon)
    slider1 = uicontrol('Style', 'slider', ...
    'Min', 0.00001, ...
    'Max', 10, ...
    'Value', 2, ...
    'SliderStep', [0.01, 0.1], ...
    'Units', 'normalized', ...
    'Position', [0.05, 0.05, 0.15, 0.05], ...
    'Callback', @(src, event) UpdateGaussFIltering(fig,src,res));
    uicontrol('Style', 'text', ...
        'String', 'G.F.', ...
        'Units', 'normalized', ...
        'Position', [0.1, 0.1 0.15, 0.05], ...
        'HorizontalAlignment', 'left');
else
    uicontrol('Style', 'pushbutton', 'String', 'Draw Main Polygon', ...
        'Units', 'normalized', 'Position', [0.05, 0.05, 0.15, 0.1], ...
        'Callback', @(src, event)drawMainPolygonCallback(fig, ax));
end
uicontrol('Style', 'pushbutton', 'String', 'Add Polygon Hole', ...
    'Units', 'normalized', 'Position', [0.25, 0.05, 0.15, 0.1], ...
    'Callback', @(src, event)addPolygonHoleCallback(fig, ax));
uicontrol('Style', 'pushbutton', 'String', 'Add Circular Hole', ...
    'Units', 'normalized', 'Position', [0.45, 0.05, 0.15, 0.1], ...
    'Callback', @(src, event)addCircleHoleCallback(fig, ax));
uicontrol('Style', 'pushbutton', 'String', 'Add Spline Hole', ...
    'Units', 'normalized', 'Position', [0.65, 0.05, 0.15, 0.1], ...
    'Callback', @(src, event)addSplineHoleCallback(fig, ax));
uicontrol('Style', 'pushbutton', 'String', 'Export Polygon', ...
    'Units', 'normalized', 'Position', [0.85, 0.05, 0.1, 0.1], ...
    'Callback', @(src, event)exportPolygonCallback(fig));
% keyboard

while ~evalin('base', 'exist(''polygonData'', ''var'')')
    clc
    fprintf('Waiting for the Polygon \n')
    pause(1); % Pause to prevent excessive CPU usage
end












end
