# Analiza koda — Stereo-DIC 3D pipeline (Faza 1)

> Detaljna revizija svakog dijela koda relevantnog za rješenje zadatka.
> Ocjene po komponenti: **ispravno** / **upitno** / **pogrešno**.
> Sve brojčane vrijednosti zaokružene na 2 decimale (AGENTS.md, pravilo 8).

## Sažetak ocjena

| Komponenta | Datoteka | Ocjena |
|---|---|---|
| Glavni driver | `src/Stereo3DDIC/StereoDIC3D.m` | ✅ **ispravno** |
| DLT triangulacija | `src/Stereo3DDIC/Functions/stereoTriangulate.m` | ✅ **ispravno** |
| Površinske deformacije | `src/Stereo3DDIC/Functions/surfaceStrains.m` | ✅ **ispravno** (uz poznatu osjetljivost na degenerirane elemente) |
| 2D DIC (globalni FE-DIC) | `src/T3DIC/GlobalT3DIC.m` | ✅ **ispravno** (skripta, nekoliko kozmetičkih mana) |
| Oblikovne funkcije T3 | `src/T3DIC/Functions/ShapeFunctions/*` | ✅ **ispravno** |
| Mesh generacija | `src/T3DIC/Functions/Meshing/*` | ✅ ispravno (interaktivno, ne koristi se u stereo fazi) |
| 2D deformacije (T3DIC) | `src/T3DIC/Functions/MeshCalculateStrains.m` | ✅ ispravno, ali **ne koristi se** u stereo pipelineu |

**Nije pronađen nijedan bug koji utječe na rezultate.** Konvencije koordinata i
stupnjeva slobode, koje su najrizičnije mjesto ovakvog pipelinea, provjerene su
kroz cijeli lanac i konzistentne su (v. §5). Empirijska potvrda: rekonstrukcija
referentnog oblika podudara se s `MeshDef` na 2,22·10⁻¹⁵ (strojna preciznost), a
srednja reprojekcijska pogreška je 0,20 px — obje bi vrijednosti eksplodirale da
je bilo koja konvencija (transpozicija, redoslijed stupaca, uparivanje čvorova)
pogrešna.

---

## 1. `StereoDIC3D.m` — glavni driver ✅ ispravno

**Što radi, korak po korak:**
1. **Ulazi** — učitava `Pi1`/`Pi2` (3×4 projekcijske matrice) iz
   `data/raw/Calib_plus_3D_mesh.mat` te po-kamerine 2D DIC rezultate
   (`DICresults_msh_0.mat`: `Mesh` + ćelijski niz `U` s 300 stanja).
2. **Uparivanje čvorova** — uzima `Mesh.coordinates(:,1:2)` obiju kamera kao
   referentne pikselne položaje istih 252 čvorova. Uparivanje "isti indeks = isti
   čvor" opravdano je jer su obje mreže projekcije iste 3D mreže `MeshDef`.
3. **Referentni oblik** — `Xref = stereoTriangulate(xy1, xy2, P1, P2)`.
4. **Petlja po stanjima** — deformirani pikselni položaji `xy + U{t}` trianguliraju
   se u 3D; `U3D{k} = X − Xref`. Usput se pune evolucijski nizovi `Umax`, `Uzmax`,
   `E1max`.
5. **Deformacije zadnjeg stanja** — `surfaceStrains` na punom polju.
6. **Izlazi** — `.mat` (v7.3) + tri PNG-a u `data/processed/stereo_<timestamp>/`
   (poštuje pravilo 2 iz AGENTS.md — ništa se ne piše u `data/raw/`).

**Provjere korektnosti:**
- Zbrajanje `xy1 + D1.U{t}` zahtijeva da su stupci `U` u istom poretku kao stupci
  `coordinates` — potvrđeno analizom lanca dof-ova (§5). ✅
- `frames = round(linspace(1,nAll,opt.nFrames))` — kod subsamplinga s
  `nFrames > nAll` dobili bi se duplicirani frameovi; bezopasno (default je sve).
- `clim([0 prctile(...,97)])` — robusno rezanje skale boja; ispravan pristup za
  element-wise polje s outlierima.
- Izlazni direktorij po pravilu `data/processed/<izvor_ddmmyyyy_hhmmss>`. ✅

**Napomene (nisu bugovi):**
- `E1max` se računa preko **svih** elemenata pa uključuje outliere s degeneriranih
  rubnih trokuta (do 3,87 = 387 %); niz se nigdje ne crta, ali tko ga čita iz
  `.mat`-a treba znati da nije filtriran (v. RESULTS_VALIDATION.md §3.1).
- `surfaceStrains` se u petlji poziva samo radi `E1max`; puni tenzor se čuva samo
  za zadnje stanje — svjesna ušteda memorije.

## 2. `stereoTriangulate.m` — linearna DLT triangulacija ✅ ispravno

**Što radi:** za svaki par pikselnih točaka `(uv1, uv2)` gradi standardni DLT
sustav — po dvije jednadžbe iz svake kamere oblika `u·P(3,:) − P(1,:)` i
`v·P(3,:) − P(2,:)` — te 3D točku uzima kao null-space 4×4 matrice `A` preko SVD-a
(`V(:,end)`), uz dehomogenizaciju dijeljenjem s `V(4,end)`.

**Provjere korektnosti:**
- Redoslijed redaka i predznaci odgovaraju standardnoj formulaciji linearne
  triangulacije (homogeni sustav `A·[X;1] = 0`). ✅
- `V(1:3,end).' / V(4,end)` — ispravna dehomogenizacija; degenerirala bi jedino za
  točke u beskonačnosti (`V(4)≈0`), što ovdje fizikalno nije moguće. ✅
- Konvencija `uv = [x(col), y(row)]` dosljedna s onim što driver šalje. ✅

**Napomene (nisu bugovi):**
- Nema Hartleyjeve normalizacije koordinata (kondicioniranje DLT-a). Za dobro
  kondicionirane `Pi1/Pi2` i mjernu zonu ovog zadatka to je nepotrebno —
  empirijski: referentni oblik rekonstruiran na 2,22·10⁻¹⁵.
- Petlja po točkama umjesto vektorizacije — pri 252 čvora × 300 stanja posve
  zanemarivo.
- Nema iterativnog rafiniranja (npr. optimalna triangulacija minimizacijom
  reprojekcije) — reprojekcijska pogreška 0,20 px pokazuje da linearno rješenje
  ovdje dostaje.

## 3. `surfaceStrains.m` — Green-Lagrangeove deformacije po elementu ✅ ispravno

**Što radi:** za svaki T3 element konstruira lokalnu ortonormiranu bazu u ravnini
referentnog trokuta (prvi brid + normala), projicira referentne i deformirane
bridove u tu 2D bazu, računa gradijent deformiranja `F = Ddef/Dref`, pa
Green-Lagrangeov tenzor `E = ½(FᵀF − I)`. Iz `E` daje komponente
`[Exx, Eyy, Exy]`, glavne deformacije (Mohrova konstrukcija: centar ± radijus) i
von Misesov ekvivalent.

**Provjere korektnosti:**
- Lokalna baza: `t1` normiran prvi brid, `nn` normala, druga os `cross(nn,t1)` —
  ortonormirana desna baza; projekcija `R (2×3)` korektna. ✅
- `F = Ddef/Dref` je matrična desna podjela = `Ddef·Dref⁻¹` — točno mapiranje
  referentnih bridova u deformirane. ✅
- `Exy` se sprema kao **tenzorska** (ne inženjerska) posmična komponenta, a
  formule za glavne deformacije (`r = hypot((Exx−Eyy)/2, Exy)`) i von Mises
  (`√(Exx² − Exx·Eyy + Eyy² + 3Exy²)`) dosljedno koriste tenzorsku konvenciju. ✅
  (Miješanje tenzorske/inženjerske konvencije čest je bug — ovdje ga **nema**.)
- Green-Lagrange umjesto malog tenzora: ispravno za mjerenje na zakrivljenoj
  površini s rotacijama, invarijantan na krute rotacije. ✅

**Poznata osjetljivost (upitno samo numerički, ne konceptualno):**
- Za **degenerirane (sliver) trokute** `Dref` je gotovo singularan pa `F`
  eksplodira → nefizikalni `E₁` na rubnim elementima (max 3,29 u zadnjem stanju).
  To je svojstvo svake element-wise sheme na linearnim trokutima, u vizualizaciji
  neutralizirano p97 rezom. Moguća poboljšanja: filtriranje elemenata po površini
  ili omjeru stranica, čvorovna ekstrapolacija.
- Nema zaštite od `norm(t1) = 0` (identični čvorovi) — u ovoj mreži ne postoji.

## 4. T3DIC — 2D DIC kod koji je proizveo ulazne rezultate

### 4.1 `GlobalT3DIC.m` (skripta) ✅ ispravno
**Što radi:** globalni FE-DIC (Galerkinov pristup na T3 mreži):
1. Učita slike, prva slika `f` je referenca; `[Y,X] = meshgrid` daje pikselne
   koordinatne matrice (X = redak, Y = stupac — v. §5).
2. Gradijent reference `[dfy,dfx] = gradient(f)`.
3. `MeshGeneration` (interaktivno) → `Mesh` s T3 elementima.
4. Oblikovne funkcije `T3ShapeFun` → matrice `psi_x`, `psi_y` (piksel × dof).
5. Hessian `M = LᵀL`, `L = psi_x·dfx + psi_y·dfy` (Gauss-Newton za SSD funkcional);
   uz `condest(M) > 10⁵` dodaje Tikhonovljevu regularizaciju.
6. Petlja po slikama: inkrementalno rješavanje `M·da = Lᵀρ`,
   `ρ = f − g(x+Vx, y+Vy)` s linearnom interpolacijom `griddedInterpolant`;
   inicijalizacija pomaka iz prethodne slike (bitno za praćenje kroz 300 stanja).
7. Konvergencija: promjena RMS reziduala `|dr| < 10⁻³` (sive razine) uz min. 5 /
   max. 200 iteracija.
8. Sprema `U`, `Us`, `Mesh`, `rms_r` u `DICresults_msh_*.mat`.

**Provjere korektnosti:**
- Gauss-Newton formulacija (fiksni Hessian iz gradijenta reference — tzv.
  modificirani/inverzni pristup) standardna je za globalni DIC; štedi računanje
  i stabilna je. ✅
- Inicijalizacija `a(:,count) = a(:,count−1) + da` pri prvoj iteraciji nove slike
  ispravno prenosi rješenje prethodnog stanja. ✅
- Preslagivanje izlaza `U{c} = [a(parni), a(neparni)]` — **ključno mjesto**;
  ispravno pretvara interni dof poredak (redak, stupac) u izlaznu konvenciju
  `[ux(stupac), uy(redak)]` usklađenu s `Mesh.coordinates` (§5). ✅

**Mane (kozmetičke, ne utječu na rezultat):**
- `im_num = 300` hardkodirano odmah nakon `im_num = length(images)` — namjerno za
  ovaj eksperiment, ali krhko za ponovnu upotrebu.
- Prag regularizacije napisan kao `10e4` (= 10⁵); vjerojatno je namjera bila
  `1e4`. Ovdje nebitno jer se grana aktivira samo za loše kondicioniran `M`.
- `griddedInterpolant` se stvara u svakoj iteraciji umjesto jednom po slici —
  samo performansa.
- `res{count}` drži rezidualno polje pune rezolucije za svih 300 slika u RAM-u
  (uz `flag_memory_save = 0`) — samo memorija.
- Kriterij konvergencije na `|dr|` (promjena reziduala), ne na `‖da‖` (promjena
  pomaka); uz `min_it = 5` u praksi robusno, komentar u kodu i sam sugerira
  alternativu.

### 4.2 Oblikovne funkcije (`T3ShapeFun` → `CalcT3MeshShapeFun` → `T3ElementShapeFun_V2`) ✅ ispravno
- Po elementu: afina transformacija na jedinični trokut preko rješavanja
  `B/A` (baricentrijske koordinate), oblikovne funkcije `N = [1−ξ−η, ξ, η]`,
  maska piksela unutar trokuta `0 ≤ N ≤ 1`. Standardno i točno. ✅
- Raspored u globalne matrice: `psi_x` puni **neparne**, `psi_y` **parne**
  dof-ove; bounding-box maska po elementu ograničava evaluaciju. ✅
- Postoje i MEX verzije (`Mex_functions/*.mexw64`) generirane iz istog izvora —
  ubrzanje, ista logika.

### 4.3 `MeshGeneration.m` / `CreateMesh` ✅ ispravno (izvan stereo pipelinea)
- Interaktivna petlja (dijalog "Satisfied?") oko `CreateMesh`; mreža za ovaj
  zadatak već je dana (`Mesh_1/Mesh_2` iz projekcije `MeshDef`), pa generacija
  mreže nije dio reproducibilnog stereo toka.

### 4.4 `MeshCalculateStrains.m` ✅ ispravno, ali se ne koristi
- Klasična mala-deformacija `B`-matrica na T3 elementima + opcijska čvorovna
  ekstrapolacija (prosjek susjednih elemenata) i glavne deformacije.
- U stereo pipelineu **zamijenjen** vlastitim `surfaceStrains` (3D površina traži
  lokalnu tangencijalnu bazu i Green-Lagrange, što ovaj 2D kod ne radi) — ispravna
  odluka.
- Sitnica: `nodalStrains` se dijeli unutar petlje po elementima (linija 81) —
  točan konačni rezultat, samo nepotrebno ponavljanje.

---

## 5. Konvencijski lanac koordinata i dof-ova (najrizičnije mjesto — provjereno)

Lanac kroz koji koordinate i pomaci putuju, provjeren datoteku po datoteku:

| Korak | Konvencija | Izvor |
|---|---|---|
| Slika `f(n×m)` | indeks = (redak, stupac) | MATLAB |
| `[Y,X] = meshgrid(1:m,1:n)` | `X` = **redak** (vertikala), `Y` = **stupac** | `GlobalT3DIC.m` |
| `Mesh.coordinates` | stupac 1 = `Y` (stupac slike, "x"), stupac 2 = `X` (redak, "y") | `CalcT3MeshShapeFun` uspoređuje `coord(:,2)` s `X` |
| `psi_x` / `psi_y` | neparni dof-ovi = pomak po **retku**; parni = po **stupcu** | `T3ElementShapeFun_V2` linije 47–48 |
| Warp | `ghat = F(x+Vx, y+Vy)`, `Vx = psi_x·a` (redak), `Vy = psi_y·a` (stupac) | `GlobalT3DIC.m` |
| Izlaz `U{t}` | stupac 1 = `a(parni)` = pomak po stupcu (**ux**), stupac 2 = `a(neparni)` = pomak po retku (**uy**) | `GlobalT3DIC.m` linije 200–201 |
| Stereo | `xy = coordinates(:,1:2)` = `[x(col), y(row)]`; `xy + U{t}` konzistentno; DLT redci koriste `uv(:,1)` kao u-koordinatu | `StereoDIC3D.m`, `stereoTriangulate.m` |

Zaključak: preslagivanje stupaca u `U` (linije 200–201) **točno je ono što
usklađuje** interni (redak,stupac) dof poredak s `[x,y]` konvencijom
`Mesh.coordinates` — bez njega bi stereo uparivanje bilo krivo. Empirijska
potvrda ispravnosti cijelog lanca: podudaranje s `MeshDef` na 2,22·10⁻¹⁵ i
reprojekcija 0,20 px.

## 6. Zaključak Faze 1

- **Pogrešno: ništa.**
- **Upitno (numerički, dokumentirano):** osjetljivost element-wise deformacija na
  sliver trokute (`E1max` outlieri); nedostatak Hartleyjeve normalizacije u DLT-u
  (ovdje bez posljedica).
- **Kozmetika (T3DIC skripta):** hardkodirani `im_num`, `10e4` prag, interpolant
  u petlji, memorijski trošak reziduala.
- Arhitektonski, odluka "reuse 2D DIC + minimalan novi kod (triangulacija +
  deformacije)" je zdrava: novi kod je ~120 linija i oba nova modula su
  verificirana nezavisnim provjerama.
