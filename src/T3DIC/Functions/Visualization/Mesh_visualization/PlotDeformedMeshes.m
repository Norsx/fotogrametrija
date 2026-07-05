function PlotDeformedMeshes(Mesh,Field,elements)

image = 1;
coor = Mesh.coordinates;
% Create a slider
% keyboard
[fig,slider] = CallInteractiveDeformed(coor,elements,Field,image);

sliderPosition = get(slider, 'Position');
set(slider, 'Position', [fig.Position(3) - sliderPosition(3), fig.Position(4) - sliderPosition(4), sliderPosition(3), sliderPosition(4)]);