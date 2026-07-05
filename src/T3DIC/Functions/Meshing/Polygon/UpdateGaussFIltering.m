function UpdateGaussFIltering(fig,Obj,res)
% keyboard
sliderValue = Obj.Value;
vertices = fig.UserData.vertices;


vertices_smoothed = GaussFilterPolygon(vertices,sliderValue);
simplifiedPoly = reducepoly(vertices_smoothed,0.0005);
poly_new = polyshape(simplifiedPoly);

% Update the stored processed mask
% fig.UserData.vertices = vertices_smoothed;
fig.UserData.GF = sliderValue;
% Update the displayed mask
DisplayPolyOverMask(poly_new,res)