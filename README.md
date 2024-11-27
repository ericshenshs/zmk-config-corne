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
