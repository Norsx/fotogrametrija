# T3DIC — Global T3 Digital Image Correlation (stereo correlation)

MATLAB source code for stereo Digital Image Correlation (DIC) using global
triangular (T3) finite-element meshes, imported from the assignment bundle
`4Send/`. Used for full-field displacement and strain measurement.

## Layout

| Path | Contents |
|---|---|
| `GlobalT3DIC.m` | Main DIC driver: loads images, builds gradients, runs global T3 correlation |
| `StrainAnalysis.m` | Post-processing: loads a result `.mat`, computes regular/principal strains, virtual gauge |
| `RunMeasurementUncertainty.m` · `PlotMeasurementUncertainty.m` | Measurement-uncertainty study + plots |
| `KMVT_images.m` | Image helper script |
| `Functions/` | Core library (add to path via `addpath(genpath('Functions'))`) |
| `Functions/Meshing/` | Mesh + mask generation (polygon/spline/circle holes, FE meshing) |
| `Functions/Mex_functions/` | Compiled MEX shape-function kernels (`*.mexw64`) + `codegen/` C++ sources |
| `Functions/ShapeFunctions/` · `Sorting/` · `Visualization/` · `Misc/` | Shape functions, sorting, plotting, utilities |

## Input data (not here)

Per project rules, the input `.mat` data lives outside this code tree:

- `data/raw/Calib_plus_3D_mesh.mat`, `data/raw/Mesh_1.mat`, `data/raw/Mesh_2.mat` — **read-only** input
- `data/sources/persson04mesh.pdf` — reference paper (Persson 2004) for the meshing method

## Running (MATLAB)

```matlab
cd src/T3DIC
run GlobalT3DIC.m      % select image folder when prompted
run StrainAnalysis.m   % select a saved result .mat when prompted
```

MEX kernels are prebuilt for win64 (`*.mexw64`); rebuild via `codegen` if needed.
