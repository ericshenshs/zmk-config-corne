# Readme

## ZMK, corne and Keeb
This is a ZMK configuration repo for corne.
According to Keeb, the wireless version of corne is using ZMK.
The default keymap is in https://keebmaker.com/pages/default-keymaps .
For changes other than to the keymap, refer to the ZMK docs:
https://zmk.dev/docs/development/documentation .

## Change keymaps: Use ZMK keymap config

### Default ZMK Keymap Config from Keeb
We first try to use the default ZMK keymap setup from Keeb:
https://github.com/klee813/zmk-config-corne/blob/220dceab93b265fc1394d274db34f7ed1394b255/config/corne.keymap
We print out the default keymap config and try to adapt to that configuration.

If some keymap setups can not work very well,
we will change the ZMK keymaps by modifying this ZMK repo and
by building the ZMK firmwares using this repo.

### Changed ZMK Keymap from Yiwei
We iterate the current ZMK keymap from Keeb in this repo and add the following changes:
1. Use left hand for escape.
2. Use left hand for all modifiers.
3. Use right hand for space.
4. Use right hand for enter.
5. Use right hand to switch layers.
6. Use right hand to type symbols.
7. Use left hand and layers for graved and tilde.

## `corne_prod_v9.keymap`

1. Easy to type in Neovim. Cleared.
2. The challenges are
- a) navigation between windows in chrome and across Chrome and Kitty.
- b) memorize non-character keys

Questions are:
1. What are the non-character keys?
2. How to memorize the non-character keys?
3. Can we keep all the non-character keys in one layer? If yes, how?
4. Can we use the first three layers for Neovim only?
5. If we put the other keys to a new layer, what are the keys that we need?
6. How to type the modifiers, for e.g., the control key?

## `corne_prod_v10.keymap`

We try to resolve the problems by:
1. Press `ctrl` and `shift` before switching the layer to
  2. Press symbols.
  3. Manage MacOS Windows.
  4. Navigate Chrome Windows.

2. Put all modifies on pinky fingers and use transparent key (and explicit override) to pass modifies to the next layers.
  1. Use `lm` to add modifier to both upper and lower layers.
  2. To navigate MacOS and Chrome windows.

3. Move the position of bluetooth clear to the end.

## `corne_prod_v11.keymap`

1. Provide a layer that has all the non-character operations.
  1. What are the keys that we need in the Chrome windows?
2. Provide a way to get all the modifiers in the first flow.
  1. Change RCTRL to RALT on the right hand side.

### Feature Requests for v10

1. Simplify the Neovim layers.
  1. Remove arrow keys in the first 3 layers.
2. Introduce New Layers:
  1. Function Layer: Bluetooth and RGB
  2. Operation Layer: Input Method, Screenshot, Window Management, and Chrome Management.
    1. Provide `ctrl+arrow` for mission control.
    2. Provide `ctrl+alt+arrow` for window movement.
