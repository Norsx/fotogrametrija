function [PSI_X, PSI_Y] = CalcT3MeshShapeFun(ee,coor,conn,ndof,Npx,X,Y)
% Wiki link to barycentric coordinates:
% https://en.wikipedia.org/wiki/Barycentric_coordinate_system

PSI_X = sparse(Npx,ndof);
PSI_Y = sparse(Npx,ndof);

col = [(1:length(coor))'*2-1,(1:length(coor))'*2];
fprintf('Calculating the shape functions... \n')

for kk = 1 : ee
    n_id = conn(kk,1:3);
    % keyboard
    coord = coor(n_id,1:2);
    x_min = min(coord(:,2));
    x_max = max(coord(:,2));
    y_min = min(coord(:,1));
    y_max = max(coord(:,1));

    % Create a mask for the bounding box
    Mask = (X >= x_min & X <= x_max) & (Y >= y_min & Y <= y_max);

    [psi_x,psi_y, vec] = T3ElementShapeFun_V2(coord,X(Mask),Y(Mask));


    linearIdx = vec(:,1) + (vec(:,2) - 1) * size(X,1);

    [PSI_X(linearIdx,col(n_id',1)),PSI_Y(linearIdx,col(n_id',2))] = CalcGlobalT3ShapeFun(PSI_X(linearIdx,col(n_id',1)),PSI_Y(linearIdx,col(n_id',1)),psi_x,psi_y);
    
    clear PSI_X_temp PSI_Y_temp
    % keyboard

    % if mod(kk,100) == 1
    %     sprintf('element %3d / %3d \n',int16(kk),int16(ee))
    %     % toc
    % end

end
