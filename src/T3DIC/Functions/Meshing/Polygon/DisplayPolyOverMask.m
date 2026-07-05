function DisplayPolyOverMask(poly,res)

imagesc(res); % Replace with your image if desired
axis image
colormap gray
hold on
% plot(poly,'Color','b')
plot(poly,'FaceColor','blue')
