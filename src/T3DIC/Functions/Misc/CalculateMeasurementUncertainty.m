function Unc = CalculateMeasurementUncertainty(Mesh,U,nim,px_size)
% keyboard 
for ii = 1 : nim
    U{ii} = U{ii}(:,:).*px_size;
end

Mesh.coordinates = Mesh.coordinates(:,:).*px_size;
E = MeshCalculateStrains(Mesh,U,'NodeExtrap',1);
E_princ = MeshCalculateStrains(Mesh,U,'Principal',1);

for ii = 1 : nim
    Ux(:,ii)  = U{ii}(:,1);
    Uy(:,ii)  = U{ii}(:,2);
    Exx(:,ii) = E{ii}(:,1);
    Eyy(:,ii) = E{ii}(:,2);
    Exy(:,ii) = E{ii}(:,3);
    E_1(:,ii) = E_princ{ii}(:,1);
    E_2(:,ii) = E_princ{ii}(:,2);
end
%
fprintf('Std disp_x uncer = %8.4e mm\n',sqrt(mean(var(Ux,[],2))))
fprintf('Std disp_y uncer = %8.4e mm\n',sqrt(mean(var(Uy,[],2))))
%
fprintf('Std eps_xx uncer = %8.4e\n',sqrt(mean(var(Exx,[],2))))
fprintf('Std eps_yy uncer = %8.4e\n',sqrt(mean(var(Eyy,[],2))))
fprintf('Std eps_xy uncer = %8.4e\n',sqrt(mean(var(Exy,[],2))))
%
fprintf('Std eps_1 uncer = %8.4e\n',sqrt(mean(var(E_1,[],2))))
fprintf('Std eps_2 uncer = %8.4e\n',sqrt(mean(var(E_2,[],2))))
%
Unc.Ux_unc = sqrt(mean(var(Ux,[],2)));
Unc.Uy_unc = sqrt(mean(var(Uy,[],2)));

Unc.U_unc = sqrt(Unc.Ux_unc^2 + Unc.Uy_unc^2);

Unc.Exx_unc = sqrt(mean(var(Exx,[],2)));
Unc.Eyy_unc = sqrt(mean(var(Eyy,[],2)));
Unc.Exy_unc = sqrt(mean(var(Exy,[],2)));

Unc.E_1 = sqrt(mean(var(E_1,[],2)));
Unc.E_2 = sqrt(mean(var(E_2,[],2)));
% keyboard
Unc.avg_elem_l = sqrt(mean(MeshArea(Mesh)));

