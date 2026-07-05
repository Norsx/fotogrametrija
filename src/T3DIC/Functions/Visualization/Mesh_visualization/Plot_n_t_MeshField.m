% Create an axis for plotting
ax = axes('Parent', fig);

% Plot the initial slice
% keyboard
sliceViewer(ax, displ, 1,Mask,ref_im);
 
% Store the axes handle in the figure's UserData
set(fig, 'UserData', struct('ax', ax));

% Create a slider
slider = uicontrol('Style', 'slider', 'Min', 1, 'Max', size(displ, 3), ...
    'Value', 1, 'SliderStep', [1/(size(displ, 3)-1), 1/(size(displ, 3)-1)], ...
    'Position', [fig.Position(3) - 150, fig.Position(4) - 30, 200, 20], ...
    'Callback', @(src, event) updateSlice(src, displ,Mask,ref_im,path,name));




% Move the slider to the top-right position above the figure
sliderPosition = get(slider, 'Position');
set(slider, 'Position', [fig.Position(3) - sliderPosition(3), fig.Position(4) - sliderPosition(4), sliderPosition(3), sliderPosition(4)]);