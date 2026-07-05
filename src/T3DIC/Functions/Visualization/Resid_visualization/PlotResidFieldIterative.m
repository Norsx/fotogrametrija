if flag_memory_save
    res = zeros(size(f));
    res(Mask) = rho;
    imagesc(res)
else
    res{count} = zeros(size(f));
    res{count}(Mask) = rho;
    imagesc(res{count})
end
axis image
colormap('hot')
clim([-1 1]*20)
title(['Im: ',num2str(im),', Iter: ', num2str(it),', res: ',num2str(r{count}(it)),', dr: ',num2str(dr)])
hold on
colorbar
quiver(Mesh.coordinates(:,1),Mesh.coordinates(:,2), amp.*a(2:2:ndof,count),amp.*a(1:2:ndof,count),0,'Color','y')

drawnow