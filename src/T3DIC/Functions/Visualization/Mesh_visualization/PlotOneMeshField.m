% keyboard

if size(Field,2) == 1
    trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
        Field, 'EdgeColor', 'k', 'FaceColor', 'interp');
    axis image
    axis ij
    view([0 0 90])
    colorbar

    % title('Ux')
else
    Ux = Field(:,1);
    Uy = Field(:,2);
    subplot(121)
    trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
        Ux, 'EdgeColor', 'k', 'FaceColor', 'interp');
    axis image
    axis ij
    view([0 0 90])
    title('Ux')
    colorbar
    subplot(122)
    trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
        Uy, 'EdgeColor', 'k', 'FaceColor', 'interp');
    axis image
    axis ij
    view([0 0 90])
    title('Uy')
    colorbar
end