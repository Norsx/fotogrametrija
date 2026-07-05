# STATE

## Projekt

- **Naziv**: Fotogrametrija — Stereokorelacija (T3DIC)
- **Tip**: Zadaća / Seminar
- **Kolegij**: _TBD_
- **LaTeX format**: FSB Seminar

## Trenutni fokus

- Uvezen postojeći MATLAB kod i podaci iz `4Send` za stereokorelaciju
  (Global T3 Digital Image Correlation — T3DIC). Sljedeći korak: pisanje LaTeX
  dokumentacije/seminara (`počni pisati`).

## Bilješke

- Kod je MATLAB (`.m`) + generirani C++/MEX artefakti (`codegen/`, `*.mexw64`).
- Ulazni `.mat` podaci su read-only (u `data/raw/`).

---

## Uvezeni materijali — gdje je što spremljeno (izvor: `4Send/`)

Razmješteno prema pravilima iz `AGENTS.md` (rule 2) i `.ai/config/REFERENCE.md` (Direktoriji):

| Izvorno u `4Send/` | Spremljeno u | Zašto (pravilo) |
|---|---|---|
| `T3DIC/` (svi `.m`, `Functions/`, `Mex_functions/codegen/`, `*.mexw64`) | `src/T3DIC/` | `src/` = programski kod zadatka |
| `Calib_plus_3D_mesh.mat` | `data/raw/` | Sirovi ulazni podaci — **READ-ONLY** |
| `Mesh_1.mat`, `Mesh_2.mat` | `data/raw/` | Sirovi ulazni podaci — **READ-ONLY** |
| `T3DIC/Functions/persson04mesh.pdf` | `data/sources/` | PDF literatura za RAG — praćeno Git LFS-om |

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
