function [PSI_X_temp,PSI_Y_temp] = CalcGlobalT3ShapeFun(PSI_X,PSI_Y,psi_x,psi_y)

col1 = [1,2;3,4;5,6];

PSI_X_temp = PSI_X + psi_x(:,col1(:,1));
PSI_Y_temp = PSI_Y + psi_y(:,col1(:,2));

end