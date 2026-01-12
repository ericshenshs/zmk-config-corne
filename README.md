# Readme

## ZMK, corne and Keeb
This is a ZMK configuration repo for corne pre-built by Keeb.
According to Keeb, the wireless version of corne is using ZMK.
The default keymap is in https://keebmaker.com/pages/default-keymaps .
For changes other than to the keymap, refer to the ZMK docs:
https://zmk.dev/docs/development/documentation .

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Change keymaps: Use ZMK keymap config](#change-keymaps-use-zmk-keymap-config)
  - [Default ZMK Keymap Config from Keeb](#default-zmk-keymap-config-from-keeb)
  - [Changed ZMK Keymap from Yiwei](#changed-zmk-keymap-from-yiwei)
- [(deprecated@2025.03.16) `corne_prod_v9.keymap`](#deprecated20250316-corne_prod_v9keymap)
- [(prod@2025.03.16) `corne_prod_v10.keymap`](#prod20250316-corne_prod_v10keymap)
  - [Design](#design)
  - [Feedback, Changes, Usages](#feedback-changes-usages)
- [(skip@2025.03.16) `corne_prod_v11.keymap`](#skip20250316-corne_prod_v11keymap)
  - [Feature Requests for `v11`](#feature-requests-for-v11)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Change keymaps: Use ZMK keymap config

### Default ZMK Keymap Config from Keeb
We first try to use the default ZMK keymap setup from Keeb:
https://github.com/klee813/zmk-config-corne/blob/220dceab93b265fc1394d274db34f7ed1394b255/config/corne.keymap
We print out the default keymap config and try to adapt to that configuration.

If some keymap setups can not work very well,
we will change the ZMK keymaps by modifying this ZMK repo and
by building the ZMK firmwares using this repo.
