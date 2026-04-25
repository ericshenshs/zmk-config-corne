# ZMK Deploy

Push the current keymap to GitHub, monitor the firmware build, and optionally download the artifacts.

## Steps

### 1. Verify corne.keymap is in sync
Check that `config/corne.keymap` matches the current prod version file. Warn the user if they differ.

### 2. Commit any uncommitted changes
If there are staged or unstaged changes to keymap files, offer to commit them before pushing. Use a descriptive commit message referencing the version.

### 3. Push to origin/master
```bash
git push origin master
```

### 4. Monitor the build
Get the latest run ID and watch it:
```bash
gh run list --repo ericshenshs/zmk-config-corne --limit 1
gh run watch <run-id> --repo ericshenshs/zmk-config-corne
```

Report the final status of each job:
- `build / Fetch Build Keyboards`
- `build / Build (nice_nano//zmk, corne_left)`
- `build / Build (nice_nano//zmk, corne_right)`
- `build / Merge Output Artifacts`

If any job fails, show the failed step log:
```bash
gh run view --job=<job-id> --log-failed --repo ericshenshs/zmk-config-corne
```

### 5. Download artifacts
Once the build succeeds, automatically download the firmware. Artifacts live inside this repo under:

```
artifacts/v<N>/
```

Where `<N>` is the current prod version number (read from CLAUDE.md or infer from the latest `config/corne_prod_vN.keymap`). Create the directory if it doesn't exist, then:

```bash
mkdir -p artifacts/v<N>
gh run download <run-id> --repo ericshenshs/zmk-config-corne --dir artifacts/v<N> --pattern "firmware"
```

The artifacts are nested inside a `firmware/` subdirectory after download — move them up and clean up:
```bash
mv artifacts/v<N>/firmware/* artifacts/v<N>/
rmdir artifacts/v<N>/firmware
```

Confirm the downloaded files:
```bash
ls artifacts/v<N>/
```

Then commit the new artifacts:
```bash
git add artifacts/v<N>/
git commit -m "artifacts: add v<N> firmware"
```

### Notes
- Repo: `ericshenshs/zmk-config-corne`
- Board: `nice_nano//zmk`
- Artifact files: `corne_left-nice_nano__zmk-zmk.uf2` and `corne_right-nice_nano__zmk-zmk.uf2`
- Flash by dragging the appropriate `.uf2` onto the Nice!Nano USB drive (enter bootloader with double-tap reset)
