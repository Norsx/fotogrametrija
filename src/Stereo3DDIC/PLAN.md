# Implementacijski plan — Stereo DIC (3D)

**Pristup:** 2D DIC po kameri (postojeći kod) → stereo triangulacija → 3D pomaci → deformacije.
**Načelo:** max reuse `T3DIC`, minimalne izmjene, gotove MATLAB funkcije, kratak i čist kod.

Legenda: ✅ gotovo · 🔄 u tijeku · ⬜ predstoji

---

## Faza 0 — Provjera kalibracije i geometrije ✅
- Projekcija `MeshDef` preko `Pi1/Pi2` na `frame_000001` obiju kamera → mreža pada
  točno na speckle uzorak (potvrđeno vizualno). Konvencija piksela ispravna.

## Faza 1 — 2D DIC po svakoj kameri (REUSE) ✅
- Potvrđeno: cam1 DIC mreža == `Mesh_1`, cam2 == `Mesh_2` (max|d| = 0.0) → čvorovi
  se poklapaju node-to-node. `U` = 300 frameova × 252 čvora × 2; frame 1 = referentno.
- **Novi kod:** nema (samo učitavanje postojećih `DICresults_msh_0.mat`).

## Faza 2 — Stereo triangulacija (NOVO, malo) ✅
- `Functions/stereoTriangulate.m` — DLT preko `svd` (~12 linija).
- Validacija: referenca vraća `MeshDef` na 2.3e-15; uparivanje `xy+U` potvrđeno
  reprojekcijom (0.197 px vs 4.15 px za swapped).

## Faza 3 — Polja 3D pomaka (NOVO, trivijalno) ✅
- `U3D{t} = triangulate(xy+U1, xy+U2) − Xref`. Dominira Y (os opterećenja),
  Z izvanravninski do ~0.08. Evolucija monotona s lokalizacijom ~frame 240.

## Faza 4 — Deformacije (NOVO, kratko) ✅
- `Functions/surfaceStrains.m` — in-plane Green-Lagrange u tangentnoj ravnini
  elementa (F = Ddef/Dref, E = ½(FᵀF−I)); glavne + von-Mises. E₁ ~0–12%.

## Faza 5 — Vizualizacija (built-in) ✅
- `trisurf`/`patch`: deformirani 3D oblik (pomak), polje E₁, evolucija pomaka.

## Faza 6 — Glavna skripta + spremanje ✅
- `StereoDIC3D.m` (wrapper). Izlaz u `data/processed/stereo_<ddmmyyyy_HHMMSS>/`.

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
