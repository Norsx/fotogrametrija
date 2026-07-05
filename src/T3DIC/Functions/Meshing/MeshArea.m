function A = MeshArea(Mesh)
% keyboard
conn = Mesh.connectivity;
coor = Mesh.coordinates;
A = zeros(length(coor),1);

for ii = 1 : length(conn)

    for jj = 1 : 3
        p(jj,:) = (coor(conn(ii,jj),:));
    end

    centroid = FindTriangleCentroid(p);

    for jj = 1 : 3 
        q = p;
        q(jj,:) = [centroid, 0];

        A_temp = TriangleArea(q);

        A(conn(ii,jj),1) = A(conn(ii,jj),1) + A_temp;

    end


end
