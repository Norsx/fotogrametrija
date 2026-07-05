function sliceViewer(ax,Mesh,U,elements,image,varargin)
% Clear previous slice
% keyboard
% cla(ax);
% keyboard
Ux = U{image}(:,1);
Uy = U{image}(:,2);
if size(U{1},2) > 2
    Uz = U{image}(:,3);
end
% UZ = U{image}(:,3);

field_name = varargin{1};
% keyboard
if strcmpi(field_name,'1')
    field = 1;
elseif strcmpi(field_name,'2')
    field = 2;
    % elseif strcmpi(field_name,'Uz')
    %     field = 3;
elseif strcmpi(field_name,'3')
    field = 3;
end

switch field
    case 1
        % subplot(121)
        trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
            Ux, 'EdgeColor', 'k', 'FaceColor', 'interp');
        axis image
        axis ij
        view([0 0 90])
        % title('Ux')
        colorbar
        % subplot(122)
    case 2
        trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
            Uy, 'EdgeColor', 'k', 'FaceColor', 'interp');
        axis image
        axis ij
        view([0 0 90])
        % title('Uy')
        colorbar
    case 3
        if size(U{1},2) > 2
            trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
                Uz, 'EdgeColor', 'k', 'FaceColor', 'interp');
            axis image
            axis ij
            view([0 0 90])
            % title('Uy')
            colorbar
        else

            Magnitude = sqrt(Ux.^2 + Uy.^2);

            trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2), Mesh.coordinates(:,3), ...
                Magnitude, 'EdgeColor', 'k', 'FaceColor', 'interp');
            axis image
            % axis ij
            view([0 0 90])
            % title('Magnitude U')
            colorbar
            axis ij
        end
end

% return

end