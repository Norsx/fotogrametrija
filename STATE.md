# STATE

## Projekt

- **Naziv**: Stereo korelacija digitalne slike — mjerenje ravninskih i izvanravninskih pomaka na površini (projekt br. 3)
- **Tip**: Seminar (programski zadatak)
- **Kolegij**: Fotogrametrija i vizualizacija objekata
- **Voditelj**: izv. prof. dr. sc. Zvonimir Tomičević
- **Student**: Ivan Noršić
- **LaTeX format**: FSB Seminar
- **Tekst zadatka**: [`data/raw/ZADATAK.md`](data/raw/ZADATAK.md)

## Trenutni fokus

- **Stereo-DIC (3D) kod GOTOV i validiran** ✅ — `src/Stereo3DDIC/` (2D DIC po kameri
  → stereo triangulacija `Pi1/Pi2` → 3D pomaci → deformacije). Rezultati u
  `data/processed/stereo_*/` (polja pomaka, E₁, evolucija). Vidi `src/Stereo3DDIC/PLAN.md`.
- **Seminar (LaTeX) GOTOV i PROŠIREN** ✅ — `docs/` (FSB predložak, 6 poglavlja +
  reference + 9 slika, uklj. TikZ dijagram pipelinea), kompilira Tectonicom
  (`C:/Users/ivann/AppData/Local/tectonic/tectonic.exe`) u 15-str. PDF.
- **Revizija (07.07.2026.)** ✅ — analiza koda: `docs/CODE_ANALYSIS.md` (nema bugova);
  validacija rezultata + literatura: `docs/RESULTS_VALIDATION.md`. Ključni nalaz:
  E₁ outlieri dolaze od degradirane korelacije na 3 rubna čvora kamere 2.
- **Čišćenje rubnih čvorova (opcija 1) IMPLEMENTIRANO** ✅ — `cleanEdgeNodes.m` +
  `'clean'/'cleanTol'` u `StereoDIC3D.m`; aktualni rezultati
  `data/processed/stereo_07072026_012442/`. Reproj. 0,20→0,15 px (max 6,25→1,10);
  E₁ max 328,69 %→27,36 %; „koljeno" evolucije na ~240 bilo artefakt (nagib 2,05→1,21).
  Seminar u cijelosti usklađen (17 str.); MATLAB: `C:/Program Files/MATLAB/R2025b`.
- **Dorada seminara (07.07.2026., 2. krug)** ✅ — implementirano svih 10 točaka
  korisnikove revizije: (0) mjerna nesigurnost iz 20 slika neopterećenog uzorka
  (`src/T3DIC/RunUncertaintyBatch.m` → `data/processed/uncertainty_07072026_160607/`;
  σ_U = 2,57·10⁻³ mm ≈ 0,05 px cam1, 3,40·10⁻³ mm ≈ 0,07 px cam2 + studija
  veličine elemenata), (1) ChArUco terminologija, (2–3) baza 5,91 (≈64,75 mm),
  kut 9,32°, speckle sprej, 3 N predopterećenje, 1 mm/min, (4–5) SSD kriterij,
  T3 linearni elementi ~10 px, mreža neovisna o kalibraciji, (6) sve u mm:
  px_size = 0,0502 mm/px, 218,24 px/kalib.jed. → 10,96 mm/jed.
  (`docs/code/make_unit_figures.py`), (7) obrazloženje 300 frameova,
  (8, 10) geometrija uzorka (PLA, 160 mm, luk R31) + `geometrija.jpg`,
  (9) tipfeleri/captioni/zaključak. PDF: 25 str., kompilira čisto.
- **SVE FAZE ZAVRŠENE** (kod + seminar). Za predaju: `build-docs --version v1.0`.
- Metoda: reuse `T3DIC` + MATLAB built-ins (`svd`, `trisurf`); minimalno novog koda.

## Bilješke

- Kod je MATLAB (`.m`) + generirani C++/MEX artefakti (`codegen/`, `*.mexw64`).
- Ulazni `.mat` podaci su read-only (u `data/raw/`). `Calib_plus_3D_mesh.mat`
  sadrži `Pi1`,`Pi2` (projekcijske matrice kamera) + 3D FE mrežu `MeshDef`.

---

## Uvezeni materijali — gdje je što spremljeno (izvor: `4Send/`)

Razmješteno prema pravilima iz `AGENTS.md` (rule 2) i `.ai/config/REFERENCE.md` (Direktoriji):

| Izvorno u `4Send/` | Spremljeno u | Zašto (pravilo) |
|---|---|---|
| `T3DIC/` (svi `.m`, `Functions/`, `Mex_functions/codegen/`, `*.mexw64`) | `src/T3DIC/` | `src/` = programski kod zadatka |
| `Calib_plus_3D_mesh.mat` | `data/raw/` | Sirovi ulazni podaci — **READ-ONLY** |
| `Mesh_1.mat`, `Mesh_2.mat` | `data/raw/` | Sirovi ulazni podaci — **READ-ONLY** |
| `T3DIC/Functions/persson04mesh.pdf` | `data/sources/` | PDF literatura za RAG — praćeno Git LFS-om |
| Tekst zadatka (iz PDF-a, str. 7–8) | `data/raw/ZADATAK.md` | Dani, nepromjenjivi zadatak od profesora — **READ-ONLY** |
| Snimke eksperimenta `cam1/`, `cam2/` (2×1188 PNG) | `data/raw/cam1/`, `data/raw/cam2/` | Sirove slike kamera — **READ-ONLY**, git-ignored (~1.3 GB, lokalno). Opis: [`data/raw/RECORDINGS.md`](data/raw/RECORDINGS.md) |

Napomena: `persson04mesh.pdf` (Persson 2004, mesh generation) je izmješten iz koda
u `data/sources/` jer je literatura, a ne kod. Detaljniji opis strukture koda:
`src/T3DIC/README.md`.

---

## Obavezno prije pozivanja agenta

Popuni `.ai/config/project.yaml` — `latex_architect` čita metapodatke za
naslovnicu odatle (ne iz ovog fajla):

```yaml
author_name: "Ivan Noršić"
course_name: "NAZIV KOLEGIJA"
seminar_title: "Puni naslov seminara"
seminar_title_short: "Kratki naslov za header"
professor_title: "Prof. dr. sc."
professor_name: "Ime Prezime"
```

Agent neće nastaviti dok ta 4 obavezna polja nisu popunjena:
`author_name`, `course_name`, `seminar_title`, `professor_name`.
