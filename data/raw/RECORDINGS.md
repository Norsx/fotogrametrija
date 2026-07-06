# Experiment recordings — location & description

Raw stereo camera images used for stereo-DIC. **Read-only** input.

> The image folders (`cam1/`, `cam2/`) are **git-ignored** (~1.3 GB, too large for
> git/LFS). They live **locally only** in `data/raw/`. This file (tracked) records
> where they are so the location is always known.

## Source
- Recording: `recording_20260528_165100` (28.05.2026, 16:51:00)
- Original path: `C:\Users\ivann\Downloads\recording_20260528_165100\recording_20260528_165100`

## Layout in project (names unchanged, as delivered)
| Path | Contents |
|---|---|
| `data/raw/cam1/frame_000001.png … frame_001188.png` | Camera 1 image sequence (1188 frames) |
| `data/raw/cam2/frame_000001.png … frame_001188.png` | Camera 2 image sequence (1188 frames) |
| `data/raw/cam1/DICresults/` | Pre-existing 2D DIC results for cam1 (`DICresults_msh_*.mat`, `DICresid_msh_*.mat`) |
| `data/raw/cam2/DICresults/` | Pre-existing 2D DIC results for cam2 |

## Notes
- `frame_000001.png` = reference state; subsequent frames = during deformation.
- Both cameras are synchronized (same frame count, same indexing).
- Calibration for these cameras: `Pi1`/`Pi2` in `data/raw/Calib_plus_3D_mesh.mat`.
- `DICresults/` subfolders are derived (prior 2D DIC run), kept as delivered.
