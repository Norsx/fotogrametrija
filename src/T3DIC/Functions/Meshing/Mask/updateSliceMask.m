function updateSliceMask(fig, sliderObj, operation, f)
    % Get current slider values and the processed mask
    sliderValue = round(sliderObj.Value);
    processedMask = fig.UserData.processedMask;

    % Perform the requested operation
    se = strel('disk', sliderValue);
    switch operation
        case 'dilate'
            processedMask = imdilate(processedMask, se);
        case 'erode'
            processedMask = imerode(processedMask, se);
    end

    % Update the stored processed mask
    fig.UserData.processedMask = processedMask;

    % Update the displayed mask
    maskViewer(processedMask, f);
end
