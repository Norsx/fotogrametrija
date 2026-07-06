# Implementacijski plan — Stereo DIC (3D)

**Pristup:** 2D DIC po kameri (postojeći kod) → stereo triangulacija → 3D pomaci → deformacije.
**Načelo:** max reuse `T3DIC`, minimalne izmjene, gotove MATLAB funkcije, kratak i čist kod.

Legenda: ✅ gotovo · 🔄 u tijeku · ⬜ predstoji

---

## Faza 0 — Provjera kalibracije i geometrije ✅
- Projekcija `MeshDef` preko `Pi1/Pi2` na `frame_000001` obiju kamera → mreža pada
  točno na speckle uzorak (potvrđeno vizualno). Konvencija piksela ispravna.

## Faza 1 — 2D DIC po svakoj kameri (REUSE) ⬜
- Koristi **postojeći** `T3DIC/GlobalT3DIC.m` na cam1 i cam2 sekvenci.
- Rezultati već postoje: `data/raw/cam{1,2}/DICresults/DICresults_msh_*.mat` (polje `U`).
- Zadatak faze: učitati te rezultate + `Mesh_1`/`Mesh_2`; potvrditi da čvorovi
  odgovaraju (node i u cam1 ↔ node i u cam2, jer su obje projekcije istog `MeshDef`).
- **Novi kod:** nema (samo učitavanje). Po potrebi re-run 2D DIC-a na cam2 istim meshom.

## Faza 2 — Stereo triangulacija (NOVO, malo) ⬜
- Za svaki frame i svaki čvor: iz 2D položaja u cam1 (`Mesh_1 + U1`) i cam2 (`Mesh_2 + U2`)
  rekonstruiraj 3D točku preko `Pi1/Pi2`.
- **MATLAB built-in:** `triangulate` (Computer Vision Toolbox); fallback = ~8 linija DLT (`A\b`).
- Rezultat: 3D položaji čvorova u referentnom i svim deformiranim stanjima.
- **Novi kod:** `Functions/stereoTriangulate.m` (kratko).

## Faza 3 — Polja 3D pomaka (NOVO, trivijalno) ⬜
- `U3D{t} = X3D_deformirano{t} − X3D_referentno`. Spremiti po frameu.

## Faza 4 — Deformacije (REUSE) ⬜
- Reuse `T3DIC/MeshCalculateStrains.m`; sitna prilagodba za 3D površinu
  (deformacije u tangentnoj ravnini elementa) ili primjena na projicirane koordinate.
- Glavne i ekvivalentne deformacije.

## Faza 5 — Vizualizacija (built-in) ⬜
- **MATLAB built-in:** `trisurf`/`patch` za 3D mrežu obojenu poljem
  pomaka/deformacija + prikaz deformiranog stanja. Reuse stila iz `PlotMesh`.

## Faza 6 — Glavna skripta + spremanje ⬜
- Tanki wrapper `StereoDIC3D.m` koji veže faze 1–5.
- Spremanje u `data/processed/stereo_<ddmmyyyy_HHMMSS>/` (pravilo projekta).

## Faza 7 — Seminar (LaTeX, FSB) ⬜
- `latex_architect` postavi `docs/`; poglavlja: uvod, teorija stereo-DIC,
  kalibracija/projekcija, metoda (2D DIC + triangulacija), implementacija,
  rezultati (polja pomaka/deformacija), procjena točnosti, zaključak.

---

### Sažetak "novog" koda (namjerno minimalno)
| Datoteka | Duljina | Oslonac |
|---|---|---|
| `Functions/stereoTriangulate.m` | kratko | `triangulate` / DLT (`A\b`) |
| `Functions/surfaceStrains.m` (ako treba) | kratko | reuse `MeshCalculateStrains` |
| `StereoDIC3D.m` (wrapper) | kratko | veže postojeće + gornje |
| vizualizacija | inline | `trisurf`/`patch` |

Sve ostalo (korelacija, funkcije oblika, interpolacija, mreža) = **postojeći kod / MATLAB built-in**.
