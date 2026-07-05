function maskViewer(processedMask, f)
    % Create an image to display pixels inside the mask
    % keyboard
    res = zeros(size(f));
    res(:,:) = 255;
    res(processedMask) = f(processedMask);

    % Display the mask and the corresponding image
    subplot(121);
    imagesc(processedMask);
    axis image;
    colormap gray;
    title('Mask');

    subplot(122);
    imagesc(res);
    axis image;
    colormap gray;
    title('Pixels Inside Mask');
end
