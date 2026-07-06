# Stereo3DDIC — Stereo Digital Image Correlation (3D)

Measures **3D surface displacement and strain fields** (in-plane + out-of-plane)
from two calibrated camera image sequences of a deforming specimen.

## Method (minimal, reuse-first)
1. **2D DIC per camera** — reuses the existing `../T3DIC` global FE-DIC. Results are
   already computed and stored in `data/raw/cam{1,2}/DICresults/DICresults_msh_0.mat`
   (nodal 2D displacement `U`, 300 frames, shared 252-node mesh).
2. **Stereo triangulation** — each node's 3D position is reconstructed from its 2D
   position in both cameras via the calibration matrices `Pi1`/`Pi2`
   (`Calib_plus_3D_mesh.mat`), using linear DLT (`stereoTriangulate.m`).
3. **3D displacement** = triangulated deformed shape − triangulated reference shape.
4. **Surface strains** — in-plane Green-Lagrange per element (`surfaceStrains.m`).

Node correspondence between cameras is guaranteed: both `Mesh_1` (cam1) and `Mesh_2`
(cam2) are projections of the same 3D mesh `MeshDef`.

## Files
| File | Role |
|---|---|
| `StereoDIC3D.m` | Main driver: load → triangulate → strains → save + plots |
| `Functions/stereoTriangulate.m` | Linear DLT triangulation (two views) |
| `Functions/surfaceStrains.m` | In-plane Green-Lagrange surface strains |
| `PLAN.md` | Implementation plan / progress tracker |

## Run (MATLAB)
```matlab
cd src/Stereo3DDIC
res = StereoDIC3D();                 % all 300 frames -> data/processed/stereo_<timestamp>/
res = StereoDIC3D('nFrames',50);     % quick subsample
```

## Outputs (`data/processed/stereo_<ddmmyyyy_HHMMSS>/`)
- `stereo3d_results.mat` — `Xref`, `U3D{t}` (3D nodal displacement), strains, evolution.
- `disp_magnitude.png` — deformed 3D shape coloured by |U|.
- `strain_E1.png` — major principal strain field.
- `disp_evolution.png` — max |U| and out-of-plane |Uz| vs frame.

## Validation
- Reference triangulation recovers `MeshDef` to ~1e-15 (machine precision).
- Reprojection error ~0.2 px (sub-pixel) → correct node/displacement pairing.
- Displacement grows monotonically with a localization onset (~frame 240), with a
  measurable out-of-plane component — consistent with a tensile test.

## Inputs (read-only, in `data/raw/`)
- `Calib_plus_3D_mesh.mat` — `Pi1`, `Pi2`, 3D mesh `MeshDef`.
- `cam1/`, `cam2/` — image sequences + `DICresults/` (pre-computed 2D DIC).
