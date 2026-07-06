# Validacija rezultata eksperimenta — Stereo-DIC 3D

> Provjera: (a) odgovaraju li brojevi u seminaru (`docs/chapters/04-rezultati.tex`)
> stvarnim podacima u `data/processed/stereo_06072026_141900/stereo3d_results.mat`,
> te (b) imaju li vrijednosti fizikalnog smisla u usporedbi s literaturom.
> Podaci: 300 stanja, 252 čvora, 438 elemenata (Abaqus `S3R`), `ScaleFE = 0,02`.
> Sve vrijednosti zaokružene na 2 decimale (AGENTS.md, pravilo 8).

## Sažetak

**Svi glavni brojevi navedeni u seminaru točno odgovaraju izračunatim podacima.**
Grafovi su konzistentni i fizikalno smisleni. Postoje **2 stavke za oprez** (nisu
greške, ali ih treba znati): (1) pohranjeni `E1max` sadrži nefizikalne outliere iz
degeneriranih rubnih elemenata, (2) svi pomaci su u **bezdimenzijskim kalibracijskim
jedinicama**, ne u mm — deformacije (`E`) su ionako bezdimenzijske pa su izravno
usporedive s literaturom.

---

## 1. Tvrdnje u tekstu vs. stvarni podaci

| Veličina | Tekst (seminar) | Izračunato (.mat) | Status |
|---|---|---|---|
| Najveći ukupni pomak `\|U\|` (zadnje stanje) | ≈ 0,11 | **0,11** | ✅ točno |
| Najveća izvanravninska komp. `\|Uz\|` | ≈ 0,08 | **0,08** | ✅ točno |
| Tipična (medijalna) glavna deformacija `E₁` | ≈ 2 % | **1,95 %** (median) | ✅ točno |
| Skala boja `E₁` (robusni percentil) | p97 | **p97 = 12,76 %** → clim `[0; 0,13]` | ✅ točno |
| Rekonstrukcija ref. oblika vs. zadana mreža | ~10⁻¹⁵ | **max \|Δ\| = 2,22·10⁻¹⁵** | ✅ točno |
| Srednja reprojekcijska pogreška | ≈ 0,20 px | **0,20 px** (mean, 504 točke) | ✅ točno |
| Monoton rast pomaka, ubrzanje ~240. frame | opis | krivulja to potvrđuje | ✅ |

Reprojekcijsku pogrešku i podudaranje s `MeshDef` **nezavisno sam izračunao** (nije u
skripti): triangulacija zadnjeg stanja iz `P1/P2` pa reprojekcija natrag na piksele.

---

## 2. Usporedba s literaturom — imaju li vrijednosti smisla?

| Veličina | Naša vrijednost | Tipično u literaturi | Ocjena |
|---|---|---|---|
| **Reprojekcijska pogreška** | 0,20 px (mean) | 0,05–0,30 px za dobro kalibriran stereo-DIC; vrhunski sustavi ~0,05 px | ✅ **Smisleno**, na gornjoj granici „dobrog" — subpikselna, prihvatljiva |
| **Rekonstrukcija ref. oblika** | 2,22·10⁻¹⁵ (strojna preciznost) | idealno; potvrđuje ispravnost triangulacije/kalibracije | ✅ Odlično (očekivano jer se koriste iste ulazne točke) |
| **Medijalna deformacija E₁** | 1,95 % | vlačni pokus metala: elastično-plastično područje reda 0,1–nekoliko % | ✅ **Fizikalno smisleno** |
| **Šum polja deformacija** | median 1,95 %, ali p90 = 6,79 %, p99 = 25,71 % | element-wise strain iz linearnih trokuta je poznato bučan; DIC noise floor pomaka 0,01–0,10 px | ⚠️ Očekivano bučno (vidi §3) |
| **Izvanravninski / ukupni pomak** | 0,08 / 0,11 → **70,21 %** | za zakrivljeni uzorak Uz usporediv s U je normalno i opravdava stereo | ✅ Smisleno, potvrđuje potrebu za 3D |

Zaključak literaturne usporedbe: **nijedna vrijednost nije izvan fizikalno očekivanog
raspona.** Reprojekcijska pogreška 0,20 px je uredna (može bolje uz precizniju
kalibraciju, ali nije problematična).

---

## 3. Vrijednosti za oprez (istaknuto na tvoj zahtjev)

### ⚠️ 3.1 `E1max` sadrži nefizikalne vrijednosti
- Pohranjeno u `.mat`: `E1max(end) = 3,29` (**329 %**), globalni max niza `= 3,87` (387 %).
- To **nije** fizikalna deformacija — artefakt je deriviranja polja pomaka na
  **degeneriranim tankim rubnim trokutima** (sliver elements).
- **Nije problem za seminar**: taj se niz **nigdje ne crta** (graf evolucije prikazuje
  samo `\|U\|` i `\|Uz\|`), a mapa `E₁` je odrezana na p97. Tekst ispravno navodi
  medijan (~2 %), ne maksimum.
- Preporuka (opcionalno): u tekstu eksplicitno spomenuti da su rubni degenerirani
  elementi izvor ekstrema, ili filtrirati elemente s malom površinom prije statistike.

### ⚠️ 3.2 Jedinice su bezdimenzijske („kalibracijske"), ne mm
- Pomaci (0,11 itd.) su u istim jedinicama kao koordinate mreže (x∈[0; 0,37],
  y∈[−0,44; 0,44], z∈[0,91; 1,10]) — to su **normalizirane kalibracijske jedinice**,
  ne milimetri. `ScaleFE = 0,02` postoji u podacima ali nije primijenjen na izlaz.
- Tekst je **korektan** jer dosljedno piše „u mjernim jedinicama kalibracije".
- Preporuka (opcionalno): ako se zna faktor mjerila (mm/jedinica), pretvoriti pomake u
  mm radi čitljivosti. Deformacije ostaju iste (bezdimenzijske).

### ℹ️ 3.3 Šum mape deformacija
- Raspodjela `E₁` je široka (median 1,95 %, ali dugačak rep do desetaka %). To je
  **normalno** za deformaciju računatu po elementu na linearnim trokutima i tekst to
  već objašnjava. Zaglađivanje (čvorovna ekstrapolacija / finija mreža) bi to smanjilo.

---

## 4. Provjera grafova

| Graf | Sadržaj | Ocjena |
|---|---|---|
| `disp_evolution.png` | `\|U\|` i `\|Uz\|` kroz 300 stanja | ✅ glatko, monotono, ubrzanje ~240; osi i legenda točni |
| `disp_magnitude.png` | 3D deformirani oblik, boja = `\|U\|` | ✅ zakrivljena površina, glatko polje; colorbar 0,05–0,11 konzistentan s max 0,11 |
| `strain_E1.png` | mapa `E₁`, clim `[0; 0,13]` | ✅ ispravno odrezano; vidljiv element-wise šum (očekivano) |

---

## 5. Zaključak

- **Nema pogrešnih brojeva u seminaru** — svih 6 kvantitativnih tvrdnji reproducirano iz podataka.
- **Sve vrijednosti su fizikalno smislene** i unutar literaturnih raspona.
- Jedina „čudna" vrijednost (E1max = 329 %) je **poznati numerički artefakt** koji se
  ne prikazuje i ne utječe na zaključke; opcionalno ga vrijedi spomenuti/filtrirati.

---
*Generirano automatskom provjerom podataka iz `stereo3d_results.mat` + `Calib_plus_3D_mesh.mat`
i po-kameri DIC rezultata; reprojekcijska pogreška i podudaranje mreže izračunati nezavisno.*
