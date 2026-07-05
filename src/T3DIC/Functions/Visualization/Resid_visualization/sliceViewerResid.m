function sliceViewerResid(resid,slider1Value,slider2Value)

imagesc(resid{slider1Value})
axis image
% view([0 0 90])
title(['Image ', num2str(slider1Value)])
clim([-1 1]*slider2Value)
colormap(colorbrewer('RdBu'))
colorbar

% return

end