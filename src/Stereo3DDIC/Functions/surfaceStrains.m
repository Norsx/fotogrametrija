function [Ecomp, Eprin, Evm] = surfaceStrains(Xref, conn, U3D)
% SURFACESTRAINS In-plane Green-Lagrange strains per T3 surface element.
%
%   [Ecomp, Eprin, Evm] = surfaceStrains(Xref, conn, U3D)
%
%   Xref : Nn x 3 reference 3D node coordinates.
%   conn : Ne x 3 triangular connectivity (1-based).
%   U3D  : Nn x 3 nodal 3D displacements.
%
%   Ecomp : Ne x 3 [Exx, Eyy, Exy] in each element's local tangent frame.
%   Eprin : Ne x 2 principal strains [E1, E2].
%   Evm   : Ne x 1 von-Mises equivalent strain.
%
% Deformed edges are expressed in the reference element's local orthonormal
% frame; F = Ddef/Dref, E = 1/2 (F'F - I). Standard for small-strain surface DIC.

Ne = size(conn,1);
Ecomp = zeros(Ne,3); Eprin = zeros(Ne,2); Evm = zeros(Ne,1);
for e = 1:Ne
    n = conn(e,:);
    P = Xref(n,:);  p = P + U3D(n,:);
    t1 = P(2,:)-P(1,:);  t1 = t1/norm(t1);
    nn = cross(P(2,:)-P(1,:), P(3,:)-P(1,:));  nn = nn/norm(nn);
    R  = [t1; cross(nn,t1)];                         % 2x3 local basis
    Dref = R*[P(2,:)-P(1,:); P(3,:)-P(1,:)].';        % 2x2
    Ddef = R*[p(2,:)-p(1,:); p(3,:)-p(1,:)].';        % 2x2
    F = Ddef/Dref;
    E = 0.5*(F.'*F - eye(2));
    Ecomp(e,:) = [E(1,1) E(2,2) E(1,2)];
    c = 0.5*(E(1,1)+E(2,2));  r = hypot(0.5*(E(1,1)-E(2,2)), E(1,2));
    Eprin(e,:) = [c+r, c-r];
    Evm(e) = sqrt(E(1,1)^2 - E(1,1)*E(2,2) + E(2,2)^2 + 3*E(1,2)^2);
end
end
