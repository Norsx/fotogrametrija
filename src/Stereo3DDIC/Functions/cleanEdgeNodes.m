function [U, info] = cleanEdgeNodes(U, conn, tol)
% CLEANEDGENODES Median-filter locally inconsistent nodal 2D displacements.
%
%   [U, info] = cleanEdgeNodes(U, conn, tol)
%
%   U    : cell array of Nn x 2 nodal displacements (one cell per frame).
%   conn : Ne x 3 triangle connectivity (1-based).
%   tol  : detection threshold [px] on the deviation of a node's displacement
%          from the median displacement of its mesh neighbours (default 3).
%
%   info : struct with fields
%          .tol      threshold used [px]
%          .nodes    ids of nodes replaced in at least one frame
%          .nPerFrame  number of replaced nodes per frame
%          .maxDev   largest deviation found before cleaning [px]
%
% A node whose displacement deviates from the median of its mesh neighbours
% by more than tol in a given frame is replaced by that median, frame by
% frame. Only detected outliers are touched (in the analysed data: 3 of 252
% boundary nodes whose correlation degrades because edge elements see less
% texture); the remaining field passes through unchanged, so the DIC,
% triangulation and strain algorithms are unaffected.

if nargin < 3, tol = 3; end

% node -> neighbour-node adjacency from triangle connectivity
nn = max(conn(:));
nbr = cell(nn,1);
for e = 1:size(conn,1)
    t = conn(e,:);
    nbr{t(1)} = [nbr{t(1)}, t(2:3)];
    nbr{t(2)} = [nbr{t(2)}, t([1 3])];
    nbr{t(3)} = [nbr{t(3)}, t(1:2)];
end
nbr = cellfun(@unique, nbr, 'UniformOutput', false);

info = struct('tol',tol,'nodes',[],'nPerFrame',zeros(numel(U),1),'maxDev',0);
for t = 1:numel(U)
    u = U{t};
    med = zeros(size(u));
    for i = 1:nn
        med(i,:) = median(u(nbr{i},:), 1);
    end
    dev = vecnorm(u - med, 2, 2);
    info.maxDev = max(info.maxDev, max(dev));
    bad = find(dev > tol);
    if ~isempty(bad)
        u(bad,:) = med(bad,:);
        U{t} = u;
        info.nPerFrame(t) = numel(bad);
        info.nodes = union(info.nodes, bad);
    end
end
info.nodes = info.nodes(:).';
end
