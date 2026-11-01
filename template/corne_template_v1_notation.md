<!-- [cc] Notation + design-state file for v20. Gives short names to the outer
     pinky column, the thumb keys, and the layers so designs can be discussed
     precisely, and records the agreed v20 layout so far. Referenced from the
     project CLAUDE.md so future sessions pick it up automatically. -->

# Corne Template v1 — Notation & Design

<!-- [cc] Copied from config/corne_prod_v20_notation.md; this is the frozen
     template v1 snapshot. Its keymap is corne_template_v1.keymap. -->

> Template v1 = snapshot of the v20 design; keymap: `corne_template_v1.keymap`.

v20 is forked from `corne_prod_v19.keymap`. `corne_prod_v20.keymap` is **not
written yet**; the "v20 design" section below is the agreed layout so far.

## Key notation

| Group | Keys | Numbering |
|-------|------|-----------|
| Left pinky (outer column)  | LP1, LP2, LP3 | top → bottom |
| Right pinky (outer column) | RP1, RP2, RP3 | top → bottom |
| Left thumb  | LT1, LT2, LT3 | outer → inner (LT1 farthest from center) |
| Right thumb | RT1, RT2, RT3 | outer → inner (RT1 farthest from center) |

"1" is always the outermost key on both halves, so the halves mirror each other
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

## Layer notation

`Ln` = ZMK layer index n. v20 has exactly four layers:

| Name | Index | Layer | v20 activation | v19 origin |
|------|:---:|-------|----------------|------------|
| L0 | 0 | Default (QWERTY) | base; RT3 returns here | Default (0) |
| L1 | 1 | Lower | LT3 on L0 | Lower (1) |
| L2 | 2 | Raise | LT3 on L1 | Raise (2) |
| L3 | 3 | Func  | LT3 on L2 | Func (4) |

v19 Num (3) and Template (5) are removed. Layer switches are persistent
(`&to`), not held.

## v20 design (agreed so far)

`✕` = no key (`&none`). There are **no transparent keys** in v20.

Rules:
- LP1–3, RP1–3, LT1, LT2, RT1, RT2 are `✕` on every layer (exception: LP1 on L3 = BT_CLR).
- LT3 = layer cycle: L0 → L1 → L2 → L3 (stops; `✕` on L3).
- RT3 = reset to L0 on every layer.

**L0: Default**
```
│ ✕ │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │ ✕ │
│ ✕ │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │ ✕ │
│ ✕ │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │ ✕ │
          ✕ │ ✕ │ LT3 →L1     RT3 →L0 │ ✕ │ ✕
```

**L1: Lower**
```
│ ✕ │ 1  │ 2   │ 3 │ 4   │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │ ✕ │
│ ✕ │ SC │ SCA │ ✕ │ C-b │ ✕ │   │ ← │ ↓ │ ↑ │ → │ ✕ │ ✕ │
│ ✕ │ ✕  │ ✕   │ ✕ │ ✕   │ ✕ │   │ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │
          ✕ │ ✕ │ LT3 →L2     RT3 →L0 │ ✕ │ ✕
```
SC = macOS screenshot to clipboard, SCA = screenshot with annotation, C-b = Ctrl+B.

**L2: Raise**
```
│ ✕ │ ! │ @ │ # │ $ │ % │   │ ^ │ & │ * │ ( │ ) │ ✕ │
│ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │   │ [ │ - │ = │ ] │ \ │ ✕ │
│ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │ ✕ │   │ { │ _ │ + │ } │ | │ ✕ │
          ✕ │ ✕ │ LT3 →L3     RT3 →L0 │ ✕ │ ✕
```

**L3: Func**
```
│ BT_CLR │ BT0 │ BT1 │ BT2 │ BT3 │ BT4 │   │ ✕ │ F1 │ F2  │ F3  │ F4  │ ✕ │
│ ✕      │ TOG │ EFF │ HUI │ HUD │ ✕   │   │ ✕ │ F5 │ F6  │ F7  │ F8  │ ✕ │
│ ✕      │ ✕   │ ✕   │ ✕   │ ✕   │ ✕   │   │ ✕ │ F9 │ F10 │ F11 │ F12 │ ✕ │
               ✕ │ ✕ │ ✕     RT3 →L0 │ ✕ │ ✕
```
TOG/EFF/HUI/HUD = RGB underglow toggle / effect / hue up / hue down.

### Open items
- Not yet placed anywhere: Space, Backspace, Enter, ESC, TAB; Shift, Ctrl,
  Cmd, Alt; `'` `"` `` ` `` `~`; media keys (mute/vol/prev/next/play).
