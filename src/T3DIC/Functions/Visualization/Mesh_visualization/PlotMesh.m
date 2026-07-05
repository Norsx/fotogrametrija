function PlotMesh(Mesh,varargin)
% Input variables
% MESH => Mesh needs to have Mesh.nodes, Mesh.elements, Mesh.connectivity
% and Mesh.coordinates
% OPTIONAL
% > To plot a deformed MESH, the syntax is PlotMesh(Mesh,'Deformed', U)
% > To plot displacement fields the syntax is PlotMesh(Mesh,'Field', U)
% > To change the Mesh face color the syntax is PlotMesh(Mesh,'FaceColor', 'r')
% > To change the Mesh edge color the syntax is PlotMesh(Mesh,'EdgeColor', 'r')


plot_case = 0;
coor = Mesh.coordinates;
elements = Mesh.connectivity;

FaceColor = find(strcmp(varargin,'FaceColor'));
if FaceColor ~= 0
    ColorFace = varargin{FaceColor+1};
else
    ColorFace = [0 0.7 0.7];
end

EdgeColor = find(strcmp(varargin,'EdgeColor'));
if EdgeColor ~= 0
    ColorEdge = varargin{EdgeColor+1};
else
    ColorEdge = 'k';
end

FlagDeformed = find(strcmp(varargin,'Deformed'));
if FlagDeformed ~= 0
    plot_case = 1;
    Field = varargin{FlagDeformed+1};

    tf = iscell(Field);
    if tf == 1
        field_plot_cell_flag = 1;
    else
        field_plot_cell_flag = 0;
    end
else
    plot_case = plot_case;
end

FlagField = find(strcmp(varargin,'Field'));
if FlagField ~= 0
    plot_case = 2;
    Field = varargin{FlagField+1};
    tf = iscell(Field);
    if tf == 1
        field_plot_cell_flag = 1;
    else
        field_plot_cell_flag = 0;
    end

else
    plot_case = plot_case;
end

switch plot_case
    case 0 %% Just plot mesh
        % fig = figure('Position', [50, 50, 720, 720]);
        % keyboard
        trisurf(elements, Mesh.coordinates(:,1), Mesh.coordinates(:,2),Mesh.coordinates(:,3), 'FaceColor', ColorFace, 'EdgeColor', ColorEdge);
        axis image
        axis ij
        view([0 0 90])

    case 1 %% Plot deformed mesh

        switch field_plot_cell_flag
            case 0 %% Plot field for just one t

                PlotOneMeshDeformed

            case 1 %% Plot field for a range of t
                % keyboard
                PlotDeformedMeshes(Mesh,Field,elements)

        end


    case 2 %% Plot field over t or just one t

        switch field_plot_cell_flag
            case 0 %% Plot field for just one t

                PlotOneMeshField

            case 1 %% Plot field for a range of t

                % Plot_n_t_MeshField
                PlotFields(Mesh,Field,elements)
                % keyboard

        end

    case 3

        switch field_plot_cell_flag
            case 0 %% Plot field for just one t

                PlotOneMeshField

            case 1 %% Plot field for a range of t

                % Plot_n_t_MeshField
                PlotFields(Mesh,Field,elements)
                % keyboard

        end

end


