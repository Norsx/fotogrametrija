# Regenerate stereo-DIC result figures with physical units (mm) and pixel
# equivalents. The image scale px_size = 0.0502 mm/px comes from the 2D DIC
# setup (src/T3DIC/Functions/GlobalT3DIC.m); the calibration-unit -> mm factor
# is derived by projecting the calibration 3D mesh into camera 1 and comparing
# projected (px) with 3D (calibration-unit) edge lengths.
# Outputs -> data/processed/stereo_figs_units_<ddmmyyyy_hhmmss>/
import h5py, numpy as np, os, datetime
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

ROOT = r"C:/Users/ivann/Desktop/fotogrametrija"
RESULTS = "data/processed/stereo_07072026_015551/stereo3d_results.mat"
PX_SIZE = 0.0502  # mm per pixel (GlobalT3DIC.m)
ts = datetime.datetime.now().strftime("%d%m%Y_%H%M%S")
OUT = os.path.join(ROOT, "data", "processed", f"stereo_figs_units_{ts}")
os.makedirs(OUT, exist_ok=True)

R = h5py.File(os.path.join(ROOT, RESULTS), "r")
C = h5py.File(os.path.join(ROOT, "data/raw/Calib_plus_3D_mesh.mat"), "r")

Xref = np.array(R["Xref"]).T                    # 252x3, calibration units
conn = np.array(R["conn"]).astype(int).T - 1    # 438x3, 0-based
refs = R["U3D"][()].squeeze()
U3D = [np.array(R[r]).T for r in refs]          # per-frame 252x3 displacements
Ul = U3D[-1]
frames = np.array(R["frames"]).squeeze().astype(int)
Umax = np.array(R["Umax"]).squeeze()
Uzmax = np.array(R["Uzmax"]).squeeze()
P1 = np.array(C["Pi1"]).T
Eprin = np.array(R["Eprin"]).T                  # per-element principal strains

# --- calibration-unit -> px -> mm scale ---
Xh = np.hstack([Xref, np.ones((len(Xref), 1))])
p1 = (P1 @ Xh.T).T
p1 = p1[:, :2] / p1[:, 2:3]
e = np.vstack([conn[:, [0, 1]], conn[:, [1, 2]], conn[:, [2, 0]]])
L3 = np.linalg.norm(Xref[e[:, 0]] - Xref[e[:, 1]], axis=1)
Lp = np.linalg.norm(p1[e[:, 0]] - p1[e[:, 1]], axis=1)
PX_PER_UNIT = np.median(Lp / L3)
MM_PER_UNIT = PX_PER_UNIT * PX_SIZE
print(f"px per calibration unit: {PX_PER_UNIT:.4f}")
print(f"mm per calibration unit: {MM_PER_UNIT:.4f}")

Xmm = Xref * MM_PER_UNIT
Ulmm = Ul * MM_PER_UNIT
polys_ref = Xmm[conn]

plt.rcParams.update({
    "font.size": 11, "axes.grid": True, "grid.alpha": 0.25,
    "grid.linewidth": 0.5, "axes.spines.top": False, "axes.spines.right": False,
})

def set3d(ax, X):
    ax.set_xlim(X[:, 0].min(), X[:, 0].max())
    ax.set_ylim(X[:, 1].min(), X[:, 1].max())
    ax.set_zlim(X[:, 2].min(), X[:, 2].max())
    ax.set_box_aspect((np.ptp(X[:, 0]), np.ptp(X[:, 1]), np.ptp(X[:, 2])))
    ax.view_init(elev=28, azim=-58)

# ------------------------------------------------- 1. |U| on deformed shape [mm]
Xd = (Xref + Ul) * MM_PER_UNIT
Umag = np.linalg.norm(Ulmm, axis=1)
fig = plt.figure(figsize=(8.4, 6))
ax = fig.add_subplot(111, projection="3d")
vals = Umag[conn].mean(axis=1)
pc = Poly3DCollection(Xd[conn], linewidths=0)
pc.set_array(vals); pc.set_cmap("turbo")
ax.add_collection3d(pc)
set3d(ax, Xd)
ax.set_xlabel("x [mm]"); ax.set_ylabel("y [mm]"); ax.set_zlabel("z [mm]")
ax.zaxis.set_major_locator(matplotlib.ticker.MaxNLocator(4))
cb = fig.colorbar(pc, ax=ax, shrink=0.7, pad=0.09)
cb.set_label(r"$|\mathbf{U}|$ [mm]")
ax.set_title("Iznos 3D pomaka — deformirani oblik (posljednje stanje)", pad=0)
fig.subplots_adjust(left=0, right=1, top=1, bottom=0)
fig.savefig(os.path.join(OUT, "disp_magnitude.png"), dpi=150,
            bbox_inches="tight", pad_inches=0.15)
plt.close(fig)
print(f"max |U| last state: {Umag.max():.4f} mm = {Umag.max()/PX_SIZE:.3f} px")

# ------------------------------------------------- 2. components [mm]
comp_names = ["$U_x$", "$U_y$", "$U_z$ (izvanravninski)"]
fig, axes = plt.subplots(1, 3, figsize=(13, 4.2), subplot_kw={"projection": "3d"})
vmax = np.abs(Ulmm).max()
for i, ax in enumerate(axes):
    vals = Ulmm[:, i][conn].mean(axis=1)
    pc = Poly3DCollection(polys_ref, linewidths=0)
    pc.set_array(vals); pc.set_cmap("RdBu_r"); pc.set_clim(-vmax, vmax)
    ax.add_collection3d(pc)
    set3d(ax, Xmm)
    ax.set_title(comp_names[i], fontsize=12)
    ax.set_xticklabels([]); ax.set_yticklabels([]); ax.set_zticklabels([])
cb = fig.colorbar(pc, ax=axes, shrink=0.75, pad=0.02)
cb.set_label("pomak [mm]")
fig.suptitle("Komponente 3D pomaka — posljednje deformacijsko stanje", y=0.98)
fig.savefig(os.path.join(OUT, "disp_components.png"), dpi=150, bbox_inches="tight")
plt.close(fig)
for i, nm in enumerate(["Ux", "Uy", "Uz"]):
    print(f"{nm}: min {Ulmm[:,i].min():.4f} max {Ulmm[:,i].max():.4f} mm")

# ------------------------------------------------- 3. evolution [mm] + [px]
Umax_mm, Uzmax_mm = Umax * MM_PER_UNIT, Uzmax * MM_PER_UNIT
fig, ax = plt.subplots(figsize=(8.6, 4.6))
ax.plot(frames, Umax_mm, lw=1.6, label=r"max $|\mathbf{U}|$")
ax.plot(frames, Uzmax_mm, lw=1.6, label=r"max $|U_z|$ (izvanravninski)")
ax.set_xlabel("Slika (deformacijsko stanje)")
ax.set_ylabel("Pomak [mm]")
ax2 = ax.secondary_yaxis(
    "right", functions=(lambda v: v / PX_SIZE, lambda v: v * PX_SIZE))
ax2.set_ylabel("Pomak [px]")
ax.legend(loc="upper left", frameon=False)
ax.set_title("Evolucija najvećeg pomaka kroz pokus")
fig.tight_layout()
fig.savefig(os.path.join(OUT, "disp_evolution.png"), dpi=150)
plt.close(fig)
plateau = Umax_mm[:30]
print(f"plateau (frames 1-30) max|U|: mean {plateau.mean():.4f} mm "
      f"= {plateau.mean()/PX_SIZE:.3f} px")
print(f"last: max|U| {Umax_mm[-1]:.4f} mm, max|Uz| {Uzmax_mm[-1]:.4f} mm "
      f"({Umax_mm[-1]/PX_SIZE:.2f} px, {Uzmax_mm[-1]/PX_SIZE:.2f} px)")

# ------------------------------------------------- 4. strain E1 [-], axes in mm
fig = plt.figure(figsize=(8.4, 6))
ax = fig.add_subplot(111, projection="3d")
E1 = Eprin[:, 0]
pc = Poly3DCollection(polys_ref, linewidths=0)
pc.set_array(E1); pc.set_cmap("turbo")
pc.set_clim(0, np.quantile(E1, 0.97))
ax.add_collection3d(pc)
set3d(ax, Xmm)
ax.set_xlabel("x [mm]"); ax.set_ylabel("y [mm]"); ax.set_zlabel("z [mm]")
ax.zaxis.set_major_locator(matplotlib.ticker.MaxNLocator(4))
cb = fig.colorbar(pc, ax=ax, shrink=0.7, pad=0.09)
cb.set_label(r"$E_1$ [--]")
ax.set_title("Glavna deformacija $E_1$ (posljednje stanje)", pad=0)
fig.subplots_adjust(left=0, right=1, top=1, bottom=0)
fig.savefig(os.path.join(OUT, "strain_E1.png"), dpi=150,
            bbox_inches="tight", pad_inches=0.15)
plt.close(fig)
print(f"E1: median {np.median(E1)*100:.2f} %, q97 {np.quantile(E1,0.97)*100:.2f} %, "
      f"max {E1.max()*100:.2f} %")

# ------------------------------------------------- 5. reference mesh, axes in mm
fig = plt.figure(figsize=(8, 5.6))
ax = fig.add_subplot(111, projection="3d")
pc = Poly3DCollection(polys_ref, facecolor="#dfe7f0", edgecolor="#5b7ea6",
                      linewidths=0.5)
ax.add_collection3d(pc)
set3d(ax, Xmm)
ax.set_xlabel("x [mm]"); ax.set_ylabel("y [mm]"); ax.set_zlabel("z [mm]")
ax.zaxis.set_major_locator(matplotlib.ticker.MaxNLocator(4))
ax.set_title("Referentni 3D oblik — mreža 252 čvora / 438 elemenata", pad=0)
fig.subplots_adjust(left=0, right=1, top=1, bottom=0)
fig.savefig(os.path.join(OUT, "mesh_ref.png"), dpi=150,
            bbox_inches="tight", pad_inches=0.15)
plt.close(fig)
print(f"mesh span [mm]: x {np.ptp(Xmm[:,0]):.2f}, y {np.ptp(Xmm[:,1]):.2f}, "
      f"z {np.ptp(Xmm[:,2]):.2f}")

# ------------------- 6. reprojection error before/after cleaning, axes in mm
d1 = h5py.File(os.path.join(ROOT, "data/raw/cam1/DICresults/DICresults_msh_0.mat"), "r")
d2 = h5py.File(os.path.join(ROOT, "data/raw/cam2/DICresults/DICresults_msh_0.mat"), "r")
P2 = np.array(C["Pi2"]).T

def as_n2(a):
    a = np.array(a); return a.T if a.shape[0] == 2 else a
def coords(d):
    c = np.array(d["Mesh"]["coordinates"]); return (c.T if c.shape[0] == 3 else c)[:, :2]
def rawU(d, t):
    return as_n2(d[d["U"][()].flat[t]])

xy1, xy2 = coords(d1), coords(d2)
u1c, u2c = as_n2(R["u1last"]), as_n2(R["u2last"])
u1r, u2r = rawU(d1, -1), rawU(d2, -1)
badnodes = np.array(R["clean"]["cam2"]["nodes"]).astype(int).squeeze() - 1

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
    p1_, p2_ = xy1 + u1, xy2 + u2
    Xd_ = tri2(p1_, p2_)
    return np.maximum(np.linalg.norm(proj(P1, Xd_) - p1_, axis=1),
                      np.linalg.norm(proj(P2, Xd_) - p2_, axis=1))
r_before = reproj_per_node(u1r, u2r)
r_after  = reproj_per_node(u1c, u2c)

fig, axes = plt.subplots(1, 2, figsize=(11.6, 4.6), sharey=True)
vmax_r = r_before.max()
for ax, r, ttl in [(axes[0], r_before, "prije čišćenja"),
                   (axes[1], r_after,  "poslije čišćenja")]:
    sc = ax.scatter(Xmm[:, 1], Xmm[:, 0], c=r, cmap="Blues", s=38,
                    edgecolors="#40506080", linewidths=0.4, vmin=0, vmax=vmax_r)
    ax.set_xlabel("y [mm]")
    ax.set_title(ttl)
    ax.margins(x=0.08, y=0.12)
    ax.invert_yaxis()
axes[0].set_ylabel("x [mm]")
axes[0].scatter(Xmm[badnodes, 1], Xmm[badnodes, 0], facecolors="none",
                edgecolors="#c0392b", s=140, linewidths=1.6)
for i in badnodes:
    dx = -55 if Xmm[i, 1] > 0 else 8
    axes[0].annotate(f"{r_before[i]:.2f} px", (Xmm[i, 1], Xmm[i, 0]),
                     textcoords="offset points", xytext=(dx, 6), fontsize=9,
                     color="#c0392b")
cb = fig.colorbar(sc, ax=axes, shrink=0.9, pad=0.02)
cb.set_label("max. reprojekcijska pogreška [px]")
fig.suptitle("Reprojekcijska pogreška po čvoru — posljednje stanje", y=1.0)
fig.savefig(os.path.join(OUT, "reproj_error.png"), dpi=150, bbox_inches="tight")
plt.close(fig)

print("Output:", OUT)
for f in sorted(os.listdir(OUT)):
    print("  ", f)
