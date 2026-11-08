<!-- [cc] Notation + design-state file for v22 (forked from v21). Gives short names to the outer
     pinky column, the thumb keys, and the layers so designs can be discussed
     precisely, and records the agreed v20 layout so far. Referenced from the
     project CLAUDE.md so future sessions pick it up automatically. -->

# Corne v22 — Notation & Design

<!-- [cc] v22 notation/design file, forked from the v21 one; keep in sync with corne_prod_v22.keymap. -->
v22 is forked from `corne_prod_v21.keymap`; design below is implemented in
`corne_prod_v22.keymap`. Changes from v21: none in key behaviour (both drafts below were reverted).
<!-- [cc] RT2-freeing was tried in a v22 draft and dropped; RT2 stays →L0. -->
RT2 on L1–L3 stays one tap back to L0, same as v21.
<!-- [cc] Return-to-L0 on SC/SCA/C-b was tried in a v22 draft and dropped. -->
L1 SC, SCA and C-b stay plain keys (stay on L1), same as v21.

v21 changes from v20 (history): L3 brightness up/down on G/B; per-layer underglow colour.

<!-- [cc] v21 per-layer underglow: layer-switch keys are macros (go_l0..go_l3)
     that switch layer and set the underglow colour. -->
### Per-layer underglow (v21)

| Layer | Underglow | Set by |
|-------|-----------|--------|
| L0 | white (hue 0, sat 0) | LT2 or RT2 on L1–L3 (`go_l0`) |
| L1 | green (hue 120, sat 100) | LT3 on L0 (`go_l1`) |
| L2 | blue (hue 240, sat 100) | LT3 on L1 (`go_l2`) |
| L3 | purple (hue 280, sat 100) | LT3 on L2 (`go_l3`) |

<!-- [cc] Macros set colour only; on/off is controlled by TOG on L3. -->
The macros only change colour, never on/off (TOG on L3 controls that).
<!-- [cc] Custom &rgb_hs behavior keeps brightness across switches. -->
Colours are set with the custom `&rgb_hs` behavior (hue + saturation only), so
brightness set with BRI/BRD persists across layer switches.

## Key notation

| Group | Keys | Numbering |
|-------|------|-----------|
| Left pinky (outer column)  | LP1, LP2, LP3 | top → bottom |
| Right pinky (outer column) | RP1, RP2, RP3 | top → bottom |
| Left thumb  | (LT0), LT1, LT2, LT3 | left → right = outer → inner (LT0 slot is empty on the Corne) |
| Right thumb | RT3, RT2, RT1, (RT0) | left → right = inner → outer (RT0 slot is empty on the Corne) |

<!-- [cc] 2026-11-08: index 0 added so Corne and Dygma Sonsei share one naming. Thumbs read LT0 LT1 LT2 LT3
     left to right; the Corne has no LT0/RT0 key, so its keys stay LT1–3 / RT1–3 and nothing renumbers.
     Index 0 (LP0, RP0, LT0, RT0) marks the Sonsei-only positions; see
     ysconfig keyboard/dygma_sonsei/v1/sonsei_vs_corne.zet (Sonsei production v1). -->
Index 0 is the outermost slot: the left thumbs read LT0 LT1 LT2 LT3 from left
to right, and the right thumbs mirror them (RT3 RT2 RT1 RT0). The Corne has no
key at index 0 (LP0, RP0, LT0, RT0); those positions exist only on the Dygma
Sonsei, so the Corne's own keys keep their names. The halves mirror each other
(LP1 ↔ RP1, LT1 ↔ RT1). The 3×5 alpha block keys are referred to by their L0
letter (e.g. "the A key", "`;` key").

```
┌──────┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬──────┐
│ LP1  │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │ RP1  │
├──────┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼──────┤
│ LP2  │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │ RP2  │
├──────┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼──────┤
│ LP3  │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │ RP3  │
└──────┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴──────┘
               ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
               │ LT1 │ LT2 │ LT3 │   │ RT3 │ RT2 │ RT1 │
               └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

ZMK key positions (0-indexed, row-major; use for combos):

| Name | Pos | Name | Pos |
|------|:---:|------|:---:|
| LP1 | 0  | RP1 | 11 |
| LP2 | 12 | RP2 | 23 |
| LP3 | 24 | RP3 | 35 |
| LT1 | 36 | RT1 | 41 |
| LT2 | 37 | RT2 | 40 |
| LT3 | 38 | RT3 | 39 |

Rows: row 1 = 0–11, row 2 = 12–23, row 3 = 24–35, thumbs = 36–41.

## Modifier notation

<!-- [cc] Short names for the four macOS modifiers, used in v20 design discussion. -->

<!-- [cc] Mn = left-hand modifier, Mnb = right-hand version of the same modifier. -->

| Modifier | Left | ZMK (left) | Right | ZMK (right) | macOS symbol |
|----------|------|:---:|-------|:---:|:---:|
| Ctrl         | M1 | `LCTRL` | M1b | `RCTRL` | ⌃ |
| Alt / Option | M2 | `LALT`  | M2b | `RALT`  | ⌥ |
| Command      | M3 | `LGUI`  | M3b | `RGUI`  | ⌘ |
| Shift        | M4 | `LSHFT` | M4b | `RSHFT` | ⇧ |

Combined modifiers are written with `+`, e.g. `M1+M3` = Ctrl+Cmd.

## Layer notation

`Ln` = ZMK layer index n. v20 has exactly four layers:

| Name | Index | Layer | v20 activation | v19 origin |
|------|:---:|-------|----------------|------------|
| L0 | 0 | Default (QWERTY) | base; LT2 or RT2 on L1–L3 | Default (0) |
| L1 | 1 | Lower | LT3 on L0 | Lower (1) |
| L2 | 2 | Raise | LT3 on L1 | Raise (2) |
| L3 | 3 | Func  | LT3 on L2 | Func (4) |

v19 Num (3) and Template (5) are removed. Layer switches are persistent
(`&to`), not held.

## v22 design

`✕` = no key (`&none`). There are **no transparent keys** in v20.

Rules:
- LP1–3, RP1–3, LT1, LT2, RT1, RT2 are `✕` on every layer, except:
  LP1 on L1/L2/L3 = `` ` `` / `~` / BT_CLR; RP2/RP3 on L2 = `'` / `"`; LP3/RP3 on L1 = M4/M4b; LP3 on L2 = M4; on L0: LP3/RP3 = M4/M4b (Shift), LT2 = BSPC, RT2 = SPC, RT1 = ENT, RP1 = M1, RP2 = `'`, LT1 = M3, LP2 = M2+BSPC, LP1 = TAB.
- LT3 = layer cycle: L0 → L1 → L2 → L3 (stops; `✕` on L3).
<!-- [cc] RT3 re-added as a per-layer jump (all &to): L0→L2, L1→L0, L2→L1, L3→L0.
     Restores a path back to L0 from every layer. -->
<!-- [cc] v21: RT3 on L0 = tap ESC / hold M2 (&mt LALT ESC); ✕ on L1–L3. -->
- RT3 = tap ESC / hold M2 on L0; `✕` on L1–L3.
<!-- [cc] v21: LT2 and RT2 on L1–L3 return to L0; LP2 on L1–L3 = ✕. -->
- LT2 and RT2 on L1, L2, L3 = one-tap jump to L0. LP2 on L1–L3 = `✕`.
<!-- [cc] Usage convention: which thumb to leave L1–L3 with. -->
- Leaving L1–L3: if a space comes next, return with **RT2** (it is the Space thumb on L0, so the next RT2 tap types the space); if no space comes next, return with **LT2**. Neither key sends a character on L1–L3; they only switch to L0.

**L0: Default**
```
│TAB│ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │ M1 │
│M2+BSPC│ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │ '  │
│ M4│ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │ M4b│
          M3 │ BSPC │ LT3 →L1     RT3 ESC/M2 │ SPC │ ENT
```
<!-- [cc] RP1 = M1 (LCTRL), RP2 = M2 (LALT), LT1 = M3 (LGUI) on L0, as requested
     (left-hand keycodes even on the right-side keys RP1/RP2). -->
RP1 = M1 (`&kp LCTRL`), LT1 = M3 (`&kp LGUI`).
<!-- [cc] v21: RP2 on L0 = ' (SQT); Alt moved to RT3 hold. -->
RP2 = `'` (`&kp SQT`); M2 is now on RT3 hold (`&mt LALT ESC`).
<!-- [cc] LP2 = Alt+Backspace (M2+BSPC, delete previous word on macOS) on L0; LP1 = TAB.
     Plain ESC lives on RT3. -->
LP2 = `&kp LA(BSPC)` (M2+BSPC), LP1 = `&kp TAB`.
<!-- [cc] LP3 = M4 (LSHFT), RP3 = M4b (RSHFT) on L0; plain hold (&kp).
     LT2 = Backspace, RT2 = Space on L0 (plain keys, no layer hold).
     RT1 = Enter on L0. -->
LP3 = M4 (`&kp LSHFT`), RP3 = M4b (`&kp RSHFT`).
LT2 = `&kp BSPC`, RT2 = `&kp SPACE`, RT1 = `&kp RET`.

**L1: Lower**
```
│ ` │ 1  │ 2   │ 3 │ 4   │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │ ✕ │
│ ✕ │ SC │ SCA │ ✕ │ C-b │ ✕ │   │ ← │ ↓ │ ↑ │ → │ ✕ │ ✕ │
│ M4│ M1 │ M2  │ M3│ ✕   │ ✕ │   │ ✕ │ ✕ │M3b│M2b│M1b│M4b│
          ✕ │ →L0 │ LT3 →L2     RT3 ✕ │ →L0 │ ✕
```
<!-- [cc] L1 bottom row: mirrored modifiers. Z/X/C = M1/M2/M3 (LCTRL/LALT/LGUI),
     / . , = M1b/M2b/M3b (RCTRL/RALT/RGUI). -->
Z X C = M1 M2 M3; / . , = M1b M2b M3b (mirrored: outermost = Ctrl).
<!-- [cc] LP1 on L1 = ` (GRAVE), as in v19. LP3/RP3 on L1 = M4/M4b (Shift), as on L0. -->
LP1 = `` ` ``. LP3 = M4, RP3 = M4b.
SC = macOS screenshot to clipboard, SCA = screenshot with annotation.
<!-- [cc] v22: SC/SCA also return to L0 after the shortcut. -->
SC and SCA return to L0 (white underglow) after sending the shortcut.
<!-- [cc] v22: C-b key returns to L0 after sending Ctrl+B. -->
C-b = macro `cb_l0`: tap Ctrl+B, then go to L0 (white underglow), like `go_l0`.

**L2: Raise**
```
│ ~ │ ! │ @ │ # │ $ │ % │   │ ^ │ & │ * │ ( │ ) │ ✕ │
│ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │   │ [ │ - │ = │ ] │ \ │ ' │
│ M4│ M1│ M2│ M3│ ✕ │ ✕ │   │ { │ _ │ + │ } │ | │ " │
          ✕ │ →L0 │ LT3 →L3     RT3 ✕ │ →L0 │ ✕
```
<!-- [cc] L2: Z/X/C = M1/M2/M3 (LCTRL/LALT/LGUI), matching L1's left bottom row.
     LP1 on L2 = ~ (TILDE), as in v19. RP2 on L2 = ' (SQT), RP3 on L2 = " (DQT; moved from L3). LP3 on L2 = ✕ (Shift removed). -->
Z X C = M1 M2 M3. LP1 = `~`. RP2 = `'`. RP3 = `"`.
<!-- [cc] v21: LP3 on L2 = M4 (left Shift); * is plain STAR (not keypad). -->
LP3 = M4. `*` = `STAR` (not keypad `KP_MULTIPLY`).

**L3: Func**
```
│ BT_CLR │ BT0 │ BT1 │ BT2 │ BT3 │ BT4 │   │ ✕ │ F1 │ F2  │ F3  │ F4  │ ✕ │
│ ✕      │ TOG │ EFF │ HUI │ HUD │ BRI │   │ ✕ │ F5 │ F6  │ F7  │ F8  │ ✕ │
│ ✕      │ M1  │ M2  │ M3  │ ✕   │ BRD │   │ ✕ │ F9 │ F10 │ F11 │ F12 │ ✕ │
               ✕ │ →L0 │ ✕     RT3 ✕ │ →L0 │ ✕
```
<!-- [cc] L3: Z/X/C = M1/M2/M3, same pattern as L1/L2 (enables Cmd/Ctrl/Alt + F-keys). -->
Z X C = M1 M2 M3.
TOG/EFF/HUI/HUD = RGB underglow toggle / effect / hue up / hue down.
<!-- [cc] v21: BRI/BRD = brightness up/down on G/B. -->
BRI/BRD = underglow brightness up / down.

### Open items
<!-- [cc] Refreshed: L0 essentials are now placed. -->
- Not yet placed anywhere: media keys (mute/vol/prev/next/play).
- L3 has no Shift.
