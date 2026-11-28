# ZMK Corne Keyboard Config — Claude Instructions

## Project Overview
ZMK firmware config for a 42-key Keebmaker Corne split keyboard running on Nice!Nano controllers.

## Versioning Convention
- Active build file: `config/corne.keymap` — always an **exact copy** (not a symlink) of the current prod version
- Version files: `config/corne_prod_vN.keymap`
- To create a new version: copy the previous version, increment N, make changes
- Each version should have a matching `config/corne_prod_vN_keymap_guide.tex` and `.pdf`

## Git branches — commit on main
<!-- [cc] Added 2026-11-27: Claude's default "branch first" habit left ysconfig and
zmk-config-corne on stray branches, so other devices pulling main missed commits. -->
- In personal repos like this one (zmk-config-corne)
  commit directly on the current default branch (`main` / `master`).
- Do **not** create, switch to, or push a new branch unless the user explicitly
  asks for one. This overrides Claude Code's default "if on the default branch,
  branch first" guidance.
- To mark a version (e.g. a keymap or firmware release), use an annotated
  **tag** (`git tag -a corne-v25 -m "..."`), not a branch.
- Past versions are tagged `corne-v22`, `corne-v23`, `corne-v24` (formerly branches).

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

<!-- [cc] 2026-11-25: user rule: flashing always starts with the left half, so never ask which half is plugged in. -->
## Flashing
- **Always flash the left half first, then the right.** The first half plugged in for a flash is the left
  half; do not ask which half it is. After the left half is done, the next half plugged in is the right.
- Flash with `~/github/zmk-config-sofle/scripts/flash_serial.sh left|right <file>.uf2 <port>` (serial DFU; see
  that repo's `FLASHING.md`). On the mac_mini the NICENANO drive mounts but refuses writes, so skip copying the UF2.
- Wait until both `nice!nano v2` shows in `ioreg -p IOUSB -w0` **and** a `/dev/cu.usbmodem*` port (not the
  `NTNH` one) exists before flashing; the port appears a few seconds after the bootloader. The bootloader times
  out by itself, so flash as soon as it is up.
- If the script fails creating its venv, run it with `TMPDIR` set to a writable folder (e.g. the session scratchpad).
- Done when it prints `Device programmed.`: the left half then shows `Corne@…` on USB; the right half shows nothing.

## LaTeX Guides
- Each version has a `corne_prod_vN_keymap_guide.tex` and compiled `.pdf`
- Compile with: `pdflatex -interaction=nonstopmode <file>.tex` (run twice for correct TOC)
- Intermediate files (`.aux`, `.log`, `.out`, etc.) are gitignored

## Key Notes
- **Symlinks don't work well** for `corne.keymap` — use exact copies
<!-- [cc] 2026-11-20: v22 rebuilt from v21 exactly (old draft notes dropped) plus the Sofle v5 changes, and made prod. -->
<!-- [cc] 2026-11-23: v23 made prod (SC/SCA/C-b moved L1 → L2, L2 Ctrl+←/→ removed, L2 V = tmux nav). -->
<!-- [cc] 2026-11-23: v24 made prod (empty L1–L3 keys at LP2, LT1, RT3, L3 LT3 and L1 , . / ; ' → one-tap L0). -->
- Current prod version is **v24** (2026-11-23): v23 with one-tap →L0 on LP2, LT1 and RT3 on L1–L3, LT3 on L3,
  and L1 , . / ; ' (L1 right-hand Cmd/Alt/Ctrl removed). Before that **v23** (2026-11-23): v22 with SC/SCA/C-b moved from L1 to L2 (one-shot), L2 Ctrl+←/→
  removed, L2 V = tmux nav (C-b v, then L0). Before that **v22** (2026-11-20): v21 plus the Sofle v5 changes (one-shot L2 symbols, Ctrl+←/→ on L2 D/F,
  RT1 →L0 on L1/L3, L2 LT3 →L1, L2 RT1 →L3); v21 before that, v20 before that
- `corne.keymap` must always match the current prod version file

<!-- [cc] 2026-11-20: layer table updated for v22 -->
## Layer Structure (v22)
| Layer | Name    | Activation | Underglow |
|-------|---------|------------|-----------|
| L0    | Default | Base; LT2, RT2 (and RT1 on L1/L3) return here; any one-shot L2 symbol returns here | white |
| L1    | Lower   | Tap LT3 on L0, or LT3 on L2 | green |
| L2    | Raise   | Tap LT3 on L1 | blue |
| L3    | Func    | Tap RT1 on L2 (the only way in) | purple |

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
