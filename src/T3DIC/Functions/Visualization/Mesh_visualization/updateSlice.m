function updateSlice(fig,sliderObj,controlType, Mesh,U,elements,varargin)
ax = fig.UserData.ax;

if isempty(varargin)
    field_name = 'Ux';
else
    field_name = varargin{1};
end
% keyboard
if strcmp(controlType, 'slider')
    % Update slider value
    fig.UserData.sliderValue = round(sliderObj.Value);
    flag_update = 1;
elseif strcmp(controlType, 'button')
    % Update dropdown selection
    fig.UserData.selectedOption = sliderObj.Value;
    flag_update = 2;
end
currentSlice = fig.UserData.sliderValue;
selectedFieldIndex = fig.UserData.selectedOption;
fig.UserData.sliderLabel.String = sprintf('%.0f', round(currentSlice));
% Retrieve the field name based on the dropdown menu selection
selectedField = field_name{selectedFieldIndex};

switch flag_update
    case 1
        fig = ancestor(sliderObj, 'figure');
        data = get(fig, 'UserData');
        field = selectedFieldIndex;
        image = round(get(sliderObj, 'Value'));
        % field_num = 1;
        sliceViewer(data.ax, Mesh,U,elements,image,field_name{field});
    case 2
        fig = ancestor(sliderObj, 'figure');
        data = get(fig, 'UserData');
        field_num = round(get(sliderObj, 'Value'));
        slice = currentSlice;
        sliceViewer(data.ax, Mesh,U,elements,slice,field_name{field_num});
end

% keyboard

% keyboard
% sliceViewer(data.ax, Mesh,U,elements,image,field_name{field_num});
% keyboard
end