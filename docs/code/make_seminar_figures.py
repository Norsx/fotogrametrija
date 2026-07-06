# Generate additional seminar figures from stereo-DIC results.
# Uses the CLEANED results (edge-node outlier cleaning, see cleanEdgeNodes.m);
# the "before" state for the detection/repair figures is recomputed from the
# raw per-camera DIC results.
# Outputs -> data/processed/stereo_figs_<ddmmyyyy_hhmmss>/ (project rule 2).
import h5py, numpy as np, os, datetime
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

ROOT = r"C:/Users/ivann/Desktop/fotogrametrija"
RESULTS = "data/processed/stereo_07072026_012442/stereo3d_results.mat"
ts = datetime.datetime.now().strftime("%d%m%Y_%H%M%S")
OUT = os.path.join(ROOT, "data", "processed", f"stereo_figs_{ts}")
os.makedirs(OUT, exist_ok=True)

R = h5py.File(os.path.join(ROOT, RESULTS), "r")
C = h5py.File(os.path.join(ROOT, "data/raw/Calib_plus_3D_mesh.mat"), "r")
d1 = h5py.File(os.path.join(ROOT, "data/raw/cam1/DICresults/DICresults_msh_0.mat"), "r")
d2 = h5py.File(os.path.join(ROOT, "data/raw/cam2/DICresults/DICresults_msh_0.mat"), "r")

Xref = np.array(R["Xref"]).T                    # 252x3
conn = np.array(R["conn"]).astype(int).T - 1    # 438x3, 0-based
refs = R["U3D"][()].squeeze()
Ul = np.array(R[refs[-1]]).T                    # last-state 252x3 displacement (cleaned)
P1 = np.array(C["Pi1"]).T; P2 = np.array(C["Pi2"]).T

def as_n2(a):
    a = np.array(a); return a.T if a.shape[0] == 2 else a
def coords(d):
    c = np.array(d["Mesh"]["coordinates"]); return (c.T if c.shape[0] == 3 else c)[:, :2]
def rawU(d, t):
    return as_n2(d[d["U"][()].flat[t]])

xy1, xy2 = coords(d1), coords(d2)
u1c, u2c = as_n2(R["u1last"]), as_n2(R["u2last"])       # cleaned last-frame 2D fields
u1r, u2r = rawU(d1, -1), rawU(d2, -1)                    # raw last-frame 2D fields
TOL = float(np.array(R["clean"]["cam2"]["tol"]).squeeze())
badnodes = np.array(R["clean"]["cam2"]["nodes"]).astype(int).squeeze() - 1  # 0-based

plt.rcParams.update({
    "font.size": 11, "axes.grid": True, "grid.alpha": 0.25,
    "grid.linewidth": 0.5, "axes.spines.top": False, "axes.spines.right": False,
})

# ---------------------------------------------------------------- 1. reference mesh
fig = plt.figure(figsize=(8, 5.6))
ax = fig.add_subplot(111, projection="3d")
polys = Xref[conn]
pc = Poly3DCollection(polys, facecolor="#dfe7f0", edgecolor="#5b7ea6", linewidths=0.5)
ax.add_collection3d(pc)
ax.set_xlim(Xref[:,0].min(), Xref[:,0].max())
ax.set_ylim(Xref[:,1].min(), Xref[:,1].max())
ax.set_zlim(Xref[:,2].min(), Xref[:,2].max())
ax.set_box_aspect((np.ptp(Xref[:,0]), np.ptp(Xref[:,1]), np.ptp(Xref[:,2])))
ax.set_xlabel("x"); ax.set_ylabel("y"); ax.set_zlabel("z")
ax.zaxis.set_major_locator(matplotlib.ticker.MaxNLocator(4))
ax.view_init(elev=28, azim=-58)
ax.set_title("Referentni 3D oblik — mreža 252 čvora / 438 elemenata", pad=0)
fig.subplots_adjust(left=0, right=1, top=1, bottom=0)
fig.savefig(os.path.join(OUT, "mesh_ref.png"), dpi=150, bbox_inches="tight", pad_inches=0.15)
plt.close(fig)

# ------------------------------------------------- 2. displacement components (signed -> diverging)
comp_names = ["$U_x$", "$U_y$", "$U_z$ (izvanravninski)"]
fig, axes = plt.subplots(1, 3, figsize=(13, 4.2), subplot_kw={"projection": "3d"})
vmax = np.abs(Ul).max()
for i, ax in enumerate(axes):
    vals = Ul[:, i][conn].mean(axis=1)          # per-element mean for face colors
    pc = Poly3DCollection(polys, linewidths=0)
    pc.set_array(vals); pc.set_cmap("RdBu_r"); pc.set_clim(-vmax, vmax)
    ax.add_collection3d(pc)
    ax.set_xlim(Xref[:,0].min(), Xref[:,0].max())
    ax.set_ylim(Xref[:,1].min(), Xref[:,1].max())
    ax.set_zlim(Xref[:,2].min(), Xref[:,2].max())
    ax.set_box_aspect((np.ptp(Xref[:,0]), np.ptp(Xref[:,1]), np.ptp(Xref[:,2])))
    ax.view_init(elev=28, azim=-58)
    ax.set_title(comp_names[i], fontsize=12)
    ax.set_xticklabels([]); ax.set_yticklabels([]); ax.set_zticklabels([])
cb = fig.colorbar(pc, ax=axes, shrink=0.75, pad=0.02)
cb.set_label("pomak (kalibracijske jedinice)")
fig.suptitle("Komponente 3D pomaka — posljednje deformacijsko stanje", y=0.98)
fig.savefig(os.path.join(OUT, "disp_components.png"), dpi=150, bbox_inches="tight")
plt.close(fig)

# ------------------------------------------------- 3. reprojection error: before vs after cleaning
def tri2(a, b):
    N = len(a); X = np.zeros((N, 3))
    for i in range(N):
        A = np.vstack([a[i,0]*P1[2]-P1[0], a[i,1]*P1[2]-P1[1],
                       b[i,0]*P2[2]-P2[0], b[i,1]*P2[2]-P2[1]])
        _, _, V = np.linalg.svd(A); v = V[-1]; X[i] = v[:3]/v[3]
    return X
def proj(P, X):
    Xh = np.hstack([X, np.ones((len(X), 1))]); x = (P @ Xh.T).T
    return x[:, :2] / x[:, 2:3]
def reproj_per_node(u1, u2):
    p1, p2 = xy1 + u1, xy2 + u2
    Xd = tri2(p1, p2)
    return np.maximum(np.linalg.norm(proj(P1, Xd) - p1, axis=1),
                      np.linalg.norm(proj(P2, Xd) - p2, axis=1))
r_before = reproj_per_node(u1r, u2r)
r_after  = reproj_per_node(u1c, u2c)

fig, axes = plt.subplots(1, 2, figsize=(11.6, 4.6), sharey=True)
vmax_r = r_before.max()
for ax, r, ttl in [(axes[0], r_before, "prije čišćenja"),
                   (axes[1], r_after,  "poslije čišćenja")]:
    sc = ax.scatter(Xref[:, 1], Xref[:, 0], c=r, cmap="Blues", s=38,
                    edgecolors="#40506080", linewidths=0.4, vmin=0, vmax=vmax_r)
    ax.set_xlabel("y (kalibracijske jedinice)")
    ax.set_title(ttl)
    ax.margins(x=0.08, y=0.12)
    ax.invert_yaxis()
axes[0].set_ylabel("x (kalibracijske jedinice)")
axes[0].scatter(Xref[badnodes, 1], Xref[badnodes, 0], facecolors="none",
                edgecolors="#c0392b", s=140, linewidths=1.6)
for i in badnodes:
    dx = -55 if Xref[i, 1] > 0 else 8
    axes[0].annotate(f"{r_before[i]:.2f} px", (Xref[i, 1], Xref[i, 0]),
                     textcoords="offset points", xytext=(dx, 6), fontsize=9, color="#c0392b")
cb = fig.colorbar(sc, ax=axes, shrink=0.9, pad=0.02)
cb.set_label("max. reprojekcijska pogreška [px]")
fig.suptitle("Reprojekcijska pogreška po čvoru — posljednje stanje", y=1.0)
fig.savefig(os.path.join(OUT, "reproj_error.png"), dpi=150, bbox_inches="tight")
plt.close(fig)

# ------------------------------------------------- 4. detection: deviation-from-neighbours vs frame (cam2, raw)
adj = [set() for _ in range(len(Xref))]
for tri in conn:
    for a in tri: adj[a].update(tri.tolist())
for a in range(len(Xref)): adj[a].discard(a)
frames = list(range(0, 300, 3))
devs = {i: [] for i in badnodes}
for t in frames:
    u = rawU(d2, t)
    for i in badnodes:
        nb = list(adj[i])
        devs[i].append(np.linalg.norm(u[i] - np.median(u[nb], axis=0)))
fig, ax = plt.subplots(figsize=(8.6, 4.2))
for i, c_ in zip(badnodes, ["#0074d9", "#ff851b", "#2ecc40"]):
    ax.plot([f+1 for f in frames], devs[i], label=f"čvor {i+1}", color=c_, lw=1.5)
ax.axhline(TOL, color="#c0392b", ls="--", lw=1.2)
ax.annotate(f"prag detekcije ({TOL:.0f} px)", (5, TOL), textcoords="offset points",
            xytext=(4, 5), fontsize=9, color="#c0392b")
ax.set_xlabel("Frame"); ax.set_ylabel("odstupanje od medijana susjeda [px]")
ax.set_title("Kamera 2 — detekcija čvorova s degradiranom korelacijom")
ax.legend(frameon=False)
fig.tight_layout()
fig.savefig(os.path.join(OUT, "node_detection.png"), dpi=150)
plt.close(fig)

# --------------------- 5. projected mesh on ref/deformed frames, both cameras (2x2)
# Deformed positions use the CLEANED fields; style matches the calibration overlays.
import matplotlib.image as mpimg
cams = [
    ("Kamera 1", "cam1", xy1, u1c),
    ("Kamera 2", "cam2", xy2, u2c),
]
fig, axes = plt.subplots(2, 2, figsize=(10, 10.6))
for row, (name, folder, xy, u) in enumerate(cams):
    f0 = mpimg.imread(os.path.join(ROOT, f"data/raw/{folder}/frame_000001.png"))
    f3 = mpimg.imread(os.path.join(ROOT, f"data/raw/{folder}/frame_000300.png"))
    allp = np.vstack([xy, xy + u])
    x_min, y_min = allp.min(axis=0); x_max, y_max = allp.max(axis=0)
    mx = 0.15 * (x_max - x_min); my = 0.15 * (y_max - y_min)
    c0 = int(max(x_min - mx, 0)); c1 = int(x_max + mx)
    r0 = int(max(y_min - my, 0)); r1 = int(y_max + my)
    for col, (img, pts, state) in enumerate([
            (f0, xy,     "referentno stanje (frame 1)"),
            (f3, xy + u, "deformirano stanje (frame 300)")]):
        ax = axes[row, col]
        ax.imshow(img[r0:r1, c0:c1], cmap="gray")
        ax.triplot(pts[:, 0] - c0, pts[:, 1] - r0, conn,
                   color="#2ecc40", linewidth=0.55, alpha=0.9)
        ax.plot(pts[:, 0] - c0, pts[:, 1] - r0, ".", ms=2.2, color="#ff4136")
        ax.set_title(f"{name} — {state}", fontsize=10)
        ax.axis("off")
fig.suptitle("Projicirana mjerna mreža na referentnom i deformiranom stanju", y=0.995)
fig.tight_layout()
fig.savefig(os.path.join(OUT, "speckle_frames.png"), dpi=150, bbox_inches="tight")
plt.close(fig)

print("Output:", OUT)
for f in sorted(os.listdir(OUT)):
    print("  ", f)
