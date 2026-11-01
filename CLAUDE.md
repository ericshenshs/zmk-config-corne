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
<!-- [cc] Prod switched to v21 (2026-10-31); v21 is the canonical version on master. -->
- Current prod version is **v21** (as of 2026-10-31); v20 before that, v19 before that
- `corne.keymap` must always match the current prod version file

## Layer Structure (v21)
| Layer | Name    | Activation | Underglow |
|-------|---------|------------|-----------|
| L0    | Default | Base; LT2 or RT2 on L1–L3 returns here | white |
| L1    | Lower   | Tap LT3 on L0 | green |
| L2    | Raise   | Tap LT3 on L1 | blue |
| L3    | Func    | Tap LT3 on L2 | purple |

All switches are persistent one-tap macros (`go_l0`..`go_l3`: `&to` + colour); no hold-layers. v18–v19 had 6 layers (Num at 3, Func at 4, Template at 5).

<!-- [cc] Document the custom behavior module added in v21. -->
## Custom ZMK Module (v21+)
This repo is also a ZMK module (`zephyr/module.yml`, `Kconfig`, `CMakeLists.txt`,
`dts/bindings/behaviors/`, `src/behaviors/`). It provides `&rgb_hs <hue> <sat>`:
sets underglow hue/saturation but keeps current brightness (global locality, so
both halves update). ZMK's CI auto-loads it because `zephyr/module.yml` exists.

<!-- [cc] Added so future sessions learn the key/layer shorthand used in v20+ design discussions. -->
## Key & Layer Notation (v20+)
<!-- [cc] Each version from v20 on has its own notation/design file; read the latest one. -->
Full definitions and per-version design: `config/corne_prod_vN_notation.md` (v20, v21, …) — read the latest one before discussing or editing a version.
- **LP1–LP3 / RP1–RP3**: outer pinky column keys (left/right), numbered top → bottom (positions 0/12/24 and 11/23/35)
- **LT1–LT3 / RT1–RT3**: thumb keys, numbered outer → inner (LT1=36, LT2=37, LT3=38; RT3=39, RT2=40, RT1=41)
- Alpha-block keys are named by their L0 letter ("the A key")
- **L0–L3**: v20 layers by ZMK index — L0 Default, L1 Lower, L2 Raise, L3 Func
- **M1–M4**: left modifiers — M1 Ctrl, M2 Alt/Option, M3 Command (GUI), M4 Shift; **M1b–M4b** = right-hand versions (RCTRL, RALT, RGUI, RSHFT)
- `✕` = no key (`&none`)
<!-- [cc] Template snapshots: frozen copies of design states, not built by CI. -->
- **tvN** = template version N, saved in `template/corne_template_vN.keymap` + `_notation.md` (tv1 = v20 design snapshot before L0 work)

## GitHub Repo
`https://github.com/ericshenshs/zmk-config-corne`
