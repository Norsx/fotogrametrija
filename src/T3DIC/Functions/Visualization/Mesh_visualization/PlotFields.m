function PlotFields(Mesh,Field,elements)

% fig = figure('Position', [100, 100, 1024, 720]);
% % Create an axis for plotting


% Plot the initial slice
% keyboard
image = 1;
field_name_init = '1';
field_names = {'1','2','3'};

% Create a slider

[fig,slider,~] = CallInteractive(Mesh,elements,field_names,Field,image,field_name_init);

sliderPosition = get(slider, 'Position');
set(slider, 'Position', [fig.Position(3) - sliderPosition(3), fig.Position(4) - sliderPosition(4), sliderPosition(3), sliderPosition(4)]);