# Validacija rezultata eksperimenta — Stereo-DIC 3D

> Provjera rezultata protiv podataka i literature. **Ažurirano 07.07.2026. nakon
> implementacije čišćenja rubnih čvorova (opcija 1, `cleanEdgeNodes.m`).**
> Aktualni rezultati: `data/processed/stereo_07072026_012442/stereo3d_results.mat`
> (300 stanja, 252 čvora, 438 elemenata, `clean=true`, `cleanTol=3 px`).
> Sve vrijednosti zaokružene na 2 decimale (AGENTS.md, pravilo 8).
> Analiza koda: `docs/CODE_ANALYSIS.md`.

## Sažetak

Dijagnosticiran je i saniran **lokalizirani gubitak korelacije u kameri 2** na tri
rubna čvora (110, 229, 252): automatska detekcija (odstupanje od medijana susjeda
> 3 px) + zamjena medijanom susjeda, po frameu. Kamera 1 netaknuta, ostalih 249
čvorova netaknuto, algoritmi netaknuti. **Svi brojevi u seminaru usklađeni su s
očišćenim rezultatima i nezavisno reproducirani.**

**Ključna korekcija interpretacije:** prividno „izraženo ubrzanje oko 240. framea"
u evoluciji pomaka bilo je **artefakt dekorelacije čvorova 110/229** (odlaze baš
na ~235–260), a ne stvarno ponašanje uzorka — nakon čišćenja rast je približno
linearan (omjer nagiba 1,21 umjesto 2,05). Seminar je ispravljen i to eksplicitno
navodi.

## 1. Prije / poslije čišćenja

| Veličina | Prije | Poslije | Komentar |
|---|---|---|---|
| Reprojekcija mean | 0,20 px | **0,15 px** | median 0,13 px nepromijenjen |
| Reprojekcija max | 6,25 px | **1,10 px** | p95 = 0,33 px |
| max\|U\| (zadnje stanje) | 0,11 | **0,09** | stari max nosio je pokvareni čvor |
| max\|Uz\| | 0,08 | **0,08** | nepromijenjeno (dobar čvor) |
| max\|Uz\|/max\|U\| | 70,21 % | **89,56 %** | izvanravninski ≈ ravninski |
| E₁ max (element, zadnje st.) | 328,69 % | **27,36 %** | nefizikalni ekstremi uklonjeni |
| E₁ p97 (skala boja) | 12,76 % | **12,04 %** | |
| E₁ median | 1,95 % | **1,95 %** | tipična deformacija nepromijenjena |
| Omjer nagiba evolucije (235–300 / 150–230) | 2,05 | **1,21** | „koljeno" na ~240 bilo artefakt |
| Plato šuma (frameovi 1–20) | 0,0034 | **0,0034** | nepromijenjeno |
| Rekonstrukcija ref. oblika | 2,22·10⁻¹⁵ | 2,22·10⁻¹⁵ | čišćenje ne dira referencu |

Detekcija (iz `res.clean`): kamera 1 → **0 čvorova**; kamera 2 → **čvorovi 110,
229, 252**. Dinamika (sirovi podaci): čvor 252 naglo dekorelira na frameu ~133
(krivi lokalni minimum, skok na ~11 px); čvorovi 110/229 postupno + skok na
~235–260. Uzrok po lokaciji: čvor 252 na silueti ruba epruvete uz tamnu pozadinu;
110/229 u pojasu slabog kontrasta, u kosom pogledu kamere 2 međusobno udaljeni ~9 px.

## 2. Tvrdnje u seminaru vs. nezavisno izračunato (očišćeni podaci)

| Veličina | Tekst (seminar) | Izračunato | Status |
|---|---|---|---|
| max\|U\| (zadnje stanje) | ≈ 0,09 | 0,09 | ✅ |
| max\|Uz\| | ≈ 0,08 | 0,08 | ✅ |
| Medijalna E₁ | ≈ 2 % | 1,95 % | ✅ |
| Skala boja E₁ | p97 = 12,04 % | 12,04 % | ✅ |
| E₁ max po elementu | 27,36 % | 27,36 % | ✅ |
| Rekonstrukcija ref. oblika | ~10⁻¹⁵ | 2,22·10⁻¹⁵ | ✅ |
| Reprojekcija | ≈ 0,15 px (max 1,10) | 0,15 / 1,10 px | ✅ |
| Rubni čvorovi prije čišćenja | 3,90–6,25 px | 3,90–6,25 px | ✅ |
| Plato šuma | ≈ 0,003 | 0,0034 | ✅ |
| Blago ubrzanje pri kraju | 1,21× | 1,21 | ✅ |

## 3. Usporedba s literaturom

| Veličina | Naša vrijednost | Literatura | Ocjena |
|---|---|---|---|
| Reprojekcija | 0,15 px (mean) | 0,05–0,30 px za dobar stereo-DIC | ✅ smisleno |
| Medijalna E₁ | 1,95 % | vlačni pokus metala: 0,1 – nekoliko % | ✅ smisleno |
| Noise floor | 0,0034 kal. jed. | DIC: 0,01–0,10 px propagirano kroz triangulaciju | ✅ smisleno |
| Rubna degradacija korelacije | 3/252 čvora (prije čišćenja) | poznat problem ruba ROI-ja (Baconnais 2020; mesh-DIC radovi) | ✅ očekivano i sanirano |
| Medijalni filtar preko susjeda | tol 3 px | standardna robusna praksa čišćenja DIC polja | ✅ prihvaćeno u praksi |

Izvori:
- [Baconnais et al., Strain (2020)](https://onlinelibrary.wiley.com/doi/abs/10.1111/str.12340) — pogreške FE-DIC-a uz rub objekta.
- [Boundary Deformation Measurement by Mesh-Based DIC, Appl. Sci. (2021)](https://doi.org/10.3390/app11010053) — rubni elementi imaju manje informacija.
- [Stereo-DIC kalibracija speckle metom, Opt. Lasers Eng.](https://www.sciencedirect.com/science/article/abs/pii/S0143816619311169) — tipične reprojekcije.
- [digitalimagecorrelation.org](https://digitalimagecorrelation.org/) — noise floor smjernice.

## 4. Grafovi (očišćeni)

| Graf | Provjera | Ocjena |
|---|---|---|
| `disp_evolution.png` | završne vrijednosti 0,09/0,08; plato 1–30; približno linearan rast, bez lažnog koljena | ✅ |
| `disp_magnitude.png` | colorbar ~0,05–0,09; polje glatko; blaga rubna neravnost (subpikselna nesigurnost) | ✅ |
| `strain_E1.png` | clim [0; 0,12] = p97; max element 27,36 % | ✅ |
| `reproj_error.png` | prije/poslije na zajedničkoj skali; poslije sve < 1,10 px | ✅ |
| `node_detection.png` | skok čvora 252 na ~133; 110/229 na ~235–260; prag 3 px | ✅ |
| `speckle_frames.png` | deformirana mreža (očišćena) bez iskrivljenja u kameri 2 | ✅ |

## 5. Zaključak

- Čišćenje (opcija 1) implementirano kao automatski, opcionalan korak
  (`'clean', true`, `'cleanTol', 3`) — ne mijenja mjerne algoritme, dira samo
  detektirane outliere (3/252 čvora, jedna kamera).
- Svi brojevi u seminaru odgovaraju očišćenim podacima; nijedna vrijednost nije
  izvan fizikalno očekivanog raspona.
- Interpretacijska korekcija (lažno koljeno na ~240) transparentno je navedena u
  seminaru.

---
*Nezavisna provjera: Python/h5py; DLT triangulacija i reprojekcija reimplementirane
neovisno o MATLAB kodu; „prije" stanje rekonstruirano iz sirovih DIC rezultata.*
