# [cc] Custom ZMK behavior module. Built on BOTH halves (no central-only guard)
# because rgb_hs has global locality: the right half must run it too.
target_sources_ifdef(CONFIG_ZMK_BEHAVIOR_RGB_HUE_SAT app PRIVATE src/behaviors/behavior_rgb_hue_sat.c)
