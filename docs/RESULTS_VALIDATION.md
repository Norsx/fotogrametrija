# Validacija rezultata eksperimenta — Stereo-DIC 3D

> Provjera: (a) odgovaraju li brojevi u seminaru (`docs/chapters/04-rezultati.tex`)
> stvarnim podacima u `data/processed/stereo_06072026_141900/stereo3d_results.mat`,
> te (b) imaju li vrijednosti fizikalnog smisla u usporedbi s literaturom.
> Podaci: 300 stanja, 252 čvora, 438 elemenata (Abaqus `S3R`), `ScaleFE = 0,02`.
> Sve vrijednosti zaokružene na 2 decimale (AGENTS.md, pravilo 8).
> Analiza koda koji je proizveo rezultate: `docs/CODE_ANALYSIS.md`.

## Sažetak

**Svi glavni brojevi navedeni u seminaru točno odgovaraju izračunatim podacima**
(svih 6 kvantitativnih tvrdnji nezavisno reproducirano). Grafovi su konzistentni
s podacima i fizikalno smisleni. Nalazi za oprez: (1) pohranjeni `E1max` sadrži
nefizikalne outliere — **uzrok je degradirana 2D korelacija na rubnim čvorovima**
(ne geometrija elemenata, kako je ranije pretpostavljeno — v. §3.1); (2) svi
pomaci su u **bezdimenzijskim kalibracijskim jedinicama**, ne u mm.

---

## 1. Tvrdnje u tekstu vs. nezavisno izračunati podaci

Sve vrijednosti ispod izračunate su **nezavisno** (Python/h5py izravno iz
`.mat` datoteka; triangulacija i reprojekcija reimplementirane od nule, ne
pozivom MATLAB koda).

| Veličina | Tekst (seminar) | Izračunato | Status |
|---|---|---|---|
| Najveći ukupni pomak `\|U\|` (zadnje stanje) | ≈ 0,11 | **0,11** (globalni max 0,11 na frameu 299) | ✅ točno |
| Najveća izvanravninska komp. `\|Uz\|` | ≈ 0,08 | **0,08** | ✅ točno |
| Omjer izvanravninsko/ukupno | „usporedivo" | **70,21 %** | ✅ točno |
| Tipična (medijalna) glavna deformacija `E₁` | ≈ 2 % | **1,95 %** (median) | ✅ točno |
| Skala boja `E₁` (robusni percentil) | p97 | **p97 = 12,76 %** → clim `[0; 0,13]` | ✅ točno |
| Rekonstrukcija ref. oblika vs. zadana mreža | ~10⁻¹⁵ | **max \|Δ\| = 2,22·10⁻¹⁵**, mean 3,80·10⁻¹⁶ | ✅ točno |
| Srednja reprojekcijska pogreška | ≈ 0,20 px | **0,20 px** (mean; median 0,13; p95 0,33) | ✅ točno |
| Monoton rast, ubrzanje ~240. frame | opis | nagib 235–300 = **2,05×** nagib 150–230 | ✅ potvrđeno |
| Konzistentnost `.mat` polja | — | max\|U\| iz `U3D{end}` = pohranjeni `Umax(end)` (0,11 = 0,11) | ✅ interno konzistentno |

Dodatno izmjereno (nije u tekstu, ali korisno):
- **Plato šuma** (frameovi 1–20, prije opterećivanja): srednji max\|U\| = 0,0034
  ± 0,0012 — tj. ~3,01 % konačnog pomaka; to je efektivni noise floor mjerenja u
  kalibracijskim jedinicama.
- Krivulja `Umax` raste uz mali šum (65,89 % inkremenata pozitivno; najveći pad
  −0,0023, reda platoa šuma) — konzistentno s monotonim opterećivanjem + šum.

## 2. Usporedba s literaturom — imaju li vrijednosti smisla?

| Veličina | Naša vrijednost | Tipično u literaturi | Ocjena |
|---|---|---|---|
| **Reprojekcijska pogreška** | 0,20 px (mean), 0,13 px (median) | 0,05–0,30 px za dobro kalibriran stereo-DIC; vrhunski sustavi ~0,05 px | ✅ Smisleno; subpikselno, na gornjoj granici „dobrog" |
| **Rekonstrukcija ref. oblika** | 2,22·10⁻¹⁵ | strojna preciznost = idealno | ✅ Očekivano (iste ulazne točke definiraju `MeshDef`) |
| **Medijalna deformacija E₁** | 1,95 % | vlačni pokus metala, elastično-plastično područje: 0,1 % – nekoliko % | ✅ Fizikalno smisleno |
| **Noise floor pomaka** | ~0,0034 kal. jed. (plato 1–20) | DIC noise floor 0,01–0,10 px; naš odgovara redu veličine subpikselne pogreške propagirane kroz triangulaciju | ✅ Smisleno |
| **Rubna degradacija korelacije** | 3 čvora s reprojekcijom 3,90–6,25 px, svi na rubu mreže | poznat problem: uz rub ROI-ja subset/element ima manje informacije → veće pogreške (Baconnais 2020; mesh-DIC radovi) | ⚠️ Očekivani artefakt, dokumentiran (v. §3.1) |
| **Izvanravninski / ukupni pomak** | 70,21 % | za zakrivljeni uzorak Uz usporediv s U opravdava stereo pristup | ✅ Smisleno |

Zaključak: **nijedna vrijednost nije izvan fizikalno očekivanog raspona**;
jedini artefakti (rubni čvorovi, `E1max`) odgovaraju fenomenima poznatima iz
literature o DIC-u uz rub mjerne zone.

Izvori (internet):
- [Baconnais et al., *Improvement of the DIC close to the borders of an object*, Strain (2020)](https://onlinelibrary.wiley.com/doi/abs/10.1111/str.12340) — pogreške FE-DIC-a uz rub objekta i njihova redukcija.
- [*Boundary Deformation Measurement by Mesh-Based DIC*, Appl. Sci. (2021)](https://doi.org/10.3390/app11010053) — rubni elementi imaju manje informacija → niža točnost.
- [Calibrating stereo-DIC using synthetic speckle-pattern target, Opt. Lasers Eng.](https://www.sciencedirect.com/science/article/abs/pii/S0143816619311169) — tipične reprojekcijske pogreške 0,04–0,30 px.
- [Self-calibrated stereo-DIC accuracy, Meas. Sci. Technol. (2021)](https://ui.adsabs.harvard.edu/abs/2021MeScT..32b5201I/abstract) — kalibracijska točnost stereo-DIC sustava.
- [digitalimagecorrelation.org](https://digitalimagecorrelation.org/) — praktične smjernice: noise floor 0,01–0,10 px.

---

## 3. Vrijednosti za oprez

### ⚠️ 3.1 `E1max` outlieri — uzrok je RUBNA KORELACIJA, ne geometrija elemenata
- Pohranjeno: `E1max(end) = 3,29` (**328,69 %**), globalni max niza = 3,87.
  Nefizikalno (realna deformacija je ~2 %).
- **Nova dijagnoza (nezavisna analiza):** hipoteza o „tankim/degeneriranim
  (sliver) elementima" **ne stoji** — mreža je geometrijski uredna:
  medijan omjera stranica = 1,03 (i za najgore elemente 1,03), najmanja površina
  elementa = 66,28 % medijana. Umjesto toga:
  - 3 čvora na **rubu mreže** (čvorovi 252, 110, 229; svi na y = ±0,44) imaju
    reprojekcijsku pogrešku **3,90–6,25 px** (median svih čvorova: 0,13 px) —
    2D korelacija im je nepouzdana jer rubni elementi imaju manje slikovne
    informacije (poznat problem u literaturi — v. izvore gore);
  - 7/15 elemenata s najvećim `E₁` sadrži jedan od tih čvorova, a **12/15 leži
    uz rub** mreže;
  - isti artefakt vidljiv je i kao „nazubljen" rub na `disp_magnitude.png`.
- **Posljedice za seminar:** formulaciju „tankim rubnim elementima" u
  `04-rezultati.tex` treba korigirati u „rubnim elementima s degradiranom
  korelacijom" (ispravak u Fazi 3). Zaključci se ne mijenjaju: outlieri se ne
  crtaju (p97 rez), medijan je reprezentativan.
- Preporuka: filtrirati čvorove s reprojekcijom > 1 px (3 od 252) ili rubni pojas
  elemenata prije statistike.

### ⚠️ 3.2 Jedinice su bezdimenzijske („kalibracijske"), ne mm
- Pomaci (0,11 itd.) su u jedinicama koordinata mreže (x∈[0; 0,37],
  y∈[−0,44; 0,44], z∈[0,91; 1,10]) — **normalizirane kalibracijske jedinice**.
  `ScaleFE = 0,02` postoji u podacima, ali nije primijenjen na izlaz.
- Tekst je korektan jer dosljedno piše „u mjernim jedinicama kalibracije".
- Deformacije su bezdimenzijske pa ih to ne dira.

### ℹ️ 3.3 Šum polja deformacija
- Raspodjela `E₁` (zadnje stanje): p25 = 0,81 %, **p50 = 1,95 %**, p75 = 3,58 %,
  p90 = 6,79 %, p95 = 10,48 %, p97 = 12,76 %, p99 = 25,71 %, max = 328,69 %.
- Široki rep dolazi od kombinacije element-wise deriviranja na linearnim
  trokutima (bez zaglađivanja) i rubnih čvorova iz §3.1. Očekivano; čvorovna
  ekstrapolacija ili finija mreža bi rep smanjile.

---

## 4. Provjera grafova

| Graf | Provjera protiv podataka | Ocjena |
|---|---|---|
| `disp_evolution.png` | završne vrijednosti krivulja (0,11 / 0,08) = pohranjeni nizovi; plato šuma 1–30 vidljiv; koljeno ~240 odgovara omjeru nagiba 2,05× | ✅ konzistentno |
| `disp_magnitude.png` | colorbar 0,05–0,11 = raspon \|U\| zadnjeg stanja; glatko polje; nazubljeni rub = rubni čvorovi iz §3.1 (poznat artefakt, ne bug) | ✅ konzistentno |
| `strain_E1.png` | clim [0; 0,13] = p97; točkasti uzorak = element-wise šum; crveni klasteri uz rub = §3.1 | ✅ konzistentno |

---

## 5. Zaključak

- **Nema pogrešnih brojeva u seminaru** — svih 6 kvantitativnih tvrdnji nezavisno
  reproducirano iz podataka; interna konzistentnost `.mat` polja potvrđena.
- **Sve vrijednosti su fizikalno smislene** i unutar literaturnih raspona.
- Jedina korekcija: mehanizam `E1max` outliera je **rubna korelacija** (3 čvora,
  reprojekcija do 6,25 px), a ne geometrija elemenata — formulaciju u seminaru
  treba blago ispraviti (Faza 3). Na zaključke ne utječe.

---
*Nezavisna provjera: Python/h5py nad `stereo3d_results.mat`,
`Calib_plus_3D_mesh.mat` i po-kamerinim `DICresults_msh_0.mat`; DLT triangulacija
i reprojekcija reimplementirane neovisno o MATLAB kodu.*
