function CreateMaskFromImage(f)

img = f;  % Replace with your image file

% Convert to grayscale if needed
if size(img, 3) == 3
    grayImg = rgb2gray(img);
else
    grayImg = img;
end
[n,m] = size(img);

[Y,X] = meshgrid(1:m,1:n);

figure;
imagesc(img); axis image; colormap gray
title('Choose 2 points for ROI')
[p(:,1),p(:,2)] = ginput_r(2);
hold on
xmin = min(p(:,2));
xmax = max(p(:,2));
ymin = min(p(:,1));
ymax = max(p(:,1));

mask_temp = X > xmin & X < xmax & Y > ymin & Y < ymax;

% keyboard

% Step 1: Compute the gradients using Sobel operator
[Gx, Gy] = imgradientxy(grayImg, 'sobel');
[gradientMag, ~] = imgradient(Gx, Gy);

% Threshold the gradient magnitude to identify edges
edgeThreshold = 0.1 * max(gradientMag(:)); % Adjust this value as needed
binaryEdges = gradientMag > edgeThreshold;
% Step 2: Refine the edges using morphological operations
binaryEdges = imclose(binaryEdges, strel('disk', 5)); % Close small gaps

binaryEdges_temp = zeros(size(binaryEdges));
binaryEdges_temp(mask_temp) = binaryEdges(mask_temp);
binaryEdges = logical(binaryEdges_temp);
figure;imagesc(binaryEdges);axis image
% keyboard
% [B, L] = bwboundaries(binaryEdges, 'holes');
% 
% % Step 1: Find cells that contain matrices with at least 500 rows
% toRemove = cellfun(@(x) ismatrix(x) && size(x, 1) <= 500, B);
% 
% % Step 2: Remove those cells by indexing
% B(toRemove) = [];  % Remove the cells that meet the condition

Mask_dilate_erode(binaryEdges,img)


    
close all

