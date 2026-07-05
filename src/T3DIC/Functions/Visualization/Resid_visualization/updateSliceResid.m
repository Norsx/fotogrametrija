function updateSliceResid(fig,sliderObj,sliderType, resid)
% keyboard
if strcmp(sliderType, 'slider1')
    fig.UserData.slider1Value = round(sliderObj.Value); % Update slider1 value (round to index)
elseif strcmp(sliderType, 'slider2')
    fig.UserData.slider2Value = round(sliderObj.Value); % Update slider2 value
end
% keyboard
slider1Value = fig.UserData.slider1Value;
slider2Value = fig.UserData.slider2Value;
% Update the slider2 label
fig.UserData.slider1Label.String = sprintf('%.0f', round(slider1Value));
fig.UserData.slider2Label.String = sprintf('%.0f', round(slider2Value));

fig = ancestor(sliderObj, 'figure');
data = get(fig, 'UserData');
% image = round(get(sliderObj, 'Value'));
% field_num = 1;
sliceViewerResid(resid,slider1Value,slider2Value);

end