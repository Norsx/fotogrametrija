function sliceViewerDeformed(ax,coor,U,elements,image)
% Clear previous slice
% keyboard
% cla(ax);
% keyboard
Ux = U{image}(:,1);
Uy = U{image}(:,2);
Uz = U{image}(:,3);
% deformedNodes = coor(:,1:2) + [Ux, Uy];
deformedNodes = coor + [Ux, Uy, Uz];

% deformedNodes(:,3) = zeros(length(deformedNodes),1);
Magnitude = sqrt(Ux.^2 + Uy.^2+ Uz.^2);
% UZ = U{image}(:,3);


% subplot(121)
trisurf(elements, deformedNodes(:,1), deformedNodes(:,2), deformedNodes(:,3), ...
    Magnitude, 'EdgeColor', 'k', 'FaceColor', [0 0.7 0.7]);
axis image
axis ij
view([0 0 90])
title(['Image ',num2str(image)])
% colorbar
% subplot(122)


% return

end