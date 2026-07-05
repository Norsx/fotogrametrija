function vertices_smoothed = GaussFilterPolygon(vertices,sigma)

% sigma = 1.1; % Standard deviation of the Gaussian filter
vertices_smoothed_x = imgaussfilt(vertices(:,1), sigma);
vertices_smoothed_y = imgaussfilt(vertices(:,2), sigma);

% Combine smoothed coordinates
vertices_smoothed = [vertices_smoothed_x, vertices_smoothed_y];

% Plot the result
% figure;
% plot(vertices(:,1), vertices(:,2), '-o', 'LineWidth', 1.5);
% hold on;
% plot(vertices_smoothed(:,1), vertices_smoothed(:,2), '-r', 'LineWidth', 2);
% legend('Original Polygon', 'Smoothed Polygon');
% title('Polygon Smoothing Using Gaussian Filter');