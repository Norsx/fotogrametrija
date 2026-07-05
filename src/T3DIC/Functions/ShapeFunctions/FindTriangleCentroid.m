function centroid = FindTriangleCentroid(p)

x1 = p(1,1); y1 = p(1,2); 
x2 = p(2,1); y2 = p(2,2);
x3 = p(3,1); y3 = p(3,2);

centroid(:,1) = (x1 + x2 + x3) / 3;
centroid(:,2) = (y1 + y2 + y3) / 3;

