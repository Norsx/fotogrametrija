close all
clear all
clc

%% Load images

Path = uigetdir;

images = dir(fullfile(Path,'/','image*'));
images = {images.name}';
images = natsort(images);

f = double(imread([Path,'/',images{1}]));
kk = 0;
for ii = 2 : length(images)
    kk = kk + 1;
    g{kk} = double(imread([Path,'/',images{ii}]));
end

[n,m] = size(f);

figure;
colormap gray
imagesc(f)
xlabel('y')
ylabel('x')
axis image


[Y,X] = meshgrid(1:n,1:m);

close all
%% Choose Mask

figure;
imagesc(f)
colormap gray
axis image

hold on
[p(:,1),p(:,2)] = ginput(2);
xmin = min(p(:,1));
xmax = max(p(:,1));
ymin = min(p(:,2));
ymax = max(p(:,2));

Mask = (X > xmin & X < xmax & Y > ymin & Y < ymax)'; % Create Mask


figure;imagesc(Mask);axis image
keyboard

res = zeros(size(f));
res(Mask) = f(Mask);
imagesc(res)
colormap gray
axis image
keyboard

%% Display gradients

figure;
histogram(f(Mask))
xlabel('Gray level')
ylabel('Num. of pixels')
title('Reference image - ROI')

figure;
histogram(f)
xlabel('Gray level')
ylabel('Num. of pixels')
title('Reference image - Full')
keyboard

figure;
for ii = 1 : length(g)
    histogram(g{ii}(Mask))
    xlabel('Gray level')
    ylabel('Num. of pixels')
    title(['g = ', num2str(ii)])
    pause
end

%% Calculate differences

for ii = 1 : length(g)

    im_diff{ii} = f - g{ii};
    diff_gl(:,ii) = im_diff{ii}(Mask);

end

uncertainty = sqrt(mean(var(diff_gl,[],2)));


figure;
for ii = 1 : length(g)
    imagesc(im_diff{ii})
    axis image
    colormap gray
    % xlabel('Gray level')
    % ylabel('Num. of pixels')
    title(['delta g = ', num2str(ii)])
    clim([-1 1 ]*1)
    colorbar
    pause
end


[gx, gy] = gradient(f);
figure;
subplot(121)
imagesc(gx)
colormap gray
axis image
title('grad x')
subplot(122)
imagesc(gy)
colormap gray
title('grad y')
axis image