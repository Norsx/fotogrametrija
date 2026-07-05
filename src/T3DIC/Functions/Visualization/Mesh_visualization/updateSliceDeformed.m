function updateSliceDeformed(sliderObj, coor,U,elements,image)


fig = ancestor(sliderObj, 'figure');
data = get(fig, 'UserData');
image = round(get(sliderObj, 'Value'));
% field_num = 1;
sliceViewerDeformed(data.ax, coor,U,elements,image);

end