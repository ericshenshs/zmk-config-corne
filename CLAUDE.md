# ZMK Corne Keyboard Config — Claude Instructions

## Project Overview
ZMK firmware config for a 42-key Keebmaker Corne split keyboard running on Nice!Nano controllers.

## Versioning Convention
- Active build file: `config/corne.keymap` — always an **exact copy** (not a symlink) of the current prod version
- Version files: `config/corne_prod_vN.keymap`
- To create a new version: copy the previous version, increment N, make changes
- Each version should have a matching `config/corne_prod_vN_keymap_guide.tex` and `.pdf`

## Build System
- GitHub Actions builds on every push (`.github/workflows/build.yml`)
- Board name: `nice_nano//zmk` (requires `//zmk` suffix since ZMK's Zephyr 4.1 update, Dec 2025)
- Build matrix defined in `build.yaml`
- Produces two `.uf2` artifacts: `corne_left` and `corne_right`

## Firmware Download Location
Built artifacts go to:
`/Users/yiweishen/github/ysconfig/keyboard/keebmaker_corne/zmk_firmware/vN/`

Download with:
```
gh run download <run-id> --repo ericshenshs/zmk-config-corne --dir <path>
```

## LaTeX Guides
- Each version has a `corne_prod_vN_keymap_guide.tex` and compiled `.pdf`
- Compile with: `pdflatex -interaction=nonstopmode <file>.tex` (run twice for correct TOC)
- Intermediate files (`.aux`, `.log`, `.out`, etc.) are gitignored

## Key Notes
- **Symlinks don't work well** for `corne.keymap` — use exact copies
- Current keyboard is running **v19** (as of 2026-04-26)
- `corne.keymap` must always match the current prod version file

## Layer Structure (v18+)
| Layer | Name    | Activation |
|-------|---------|------------|
| 0     | Default | Always active |
| 1     | Lower   | Hold left BSPC thumb |
| 2     | Raise   | Hold right SPC thumb |
| 3     | Num      | Tap/hold right outer thumb |
| 4     | Func     | While in Num, hold left outer thumb |
| 5     | Template | Unused/reserved |

## GitHub Repo
`https://github.com/ericshenshs/zmk-config-corne`
