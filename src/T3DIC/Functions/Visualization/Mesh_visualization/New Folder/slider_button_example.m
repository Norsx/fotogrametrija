function slider_button_example
    % Create a figure
    fig = figure('Position', [100, 100, 400, 300]);

    % Create a slider
    slider = uicontrol('Style', 'slider', ...
        'Min', 0, 'Max', 100, 'Value', 50, ...
        'Position', [50, 50, 300, 20], ...
        'Callback', @(src, event) sliderCallback(src, fig));

    % Create a dropdown button
    button = uicontrol('Style', 'popupmenu', ...
        'String', {'Option 1', 'Option 2', 'Option 3'}, ...
        'Position', [150, 200, 100, 30], ...
        'Callback', @(src, event) buttonCallback(src, fig));

    % Add a title to display the results
    titleText = uicontrol('Style', 'text', ...
        'Position', [100, 250, 200, 20], ...
        'String', 'Adjust Slider or Select Option', ...
        'HorizontalAlignment', 'center');

    % Store UI components in the figure for shared access
    fig.UserData.sliderValue = slider.Value;
    fig.UserData.selectedOption = button.Value;
    fig.UserData.titleText = titleText;
end

function sliderCallback(slider, fig)
    % Update the slider value in the figure's UserData
    fig.UserData.sliderValue = slider.Value;

    % Update the display text
    updateDisplay(fig);
end

function buttonCallback(button, fig)
    % Update the selected option in the figure's UserData
    fig.UserData.selectedOption = button.Value;

    % Update the display text
    updateDisplay(fig);
end

function updateDisplay(fig)
    % Retrieve the updated values
    sliderValue = fig.UserData.sliderValue;
    selectedOption = fig.UserData.selectedOption;

    % Update the text display
    optionStrings = {'Option 1', 'Option 2', 'Option 3'};
    fig.UserData.titleText.String = sprintf('Slider: %.2f, Option: %s', ...
        sliderValue, optionStrings{selectedOption});
end
