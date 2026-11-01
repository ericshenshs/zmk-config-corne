/*
 * SPDX-License-Identifier: MIT
 *
 * [cc] Custom behavior: set underglow hue + saturation but KEEP the current
 * brightness. Stock &rgb_ug RGB_COLOR_HSB() always overwrites brightness,
 * which made every layer switch undo BRI/BRD. Used by the go_l0..go_l3
 * layer-switch macros in corne_prod_v21.keymap.
 *
 * Binding: &rgb_hs <hue 0-360> <sat 0-100>
 *
 * Split handling (mirrors ZMK's behavior_rgb_underglow.c): on the central
 * (left) half, binding_convert_central_state_dependent_params reads the
 * central's current brightness and packs it into param2, so the peripheral
 * (right) half applies exactly the same H/S/B. Locality is GLOBAL so ZMK
 * sends it to both halves, including when invoked from a macro.
 */

#define DT_DRV_COMPAT zmk_behavior_rgb_hue_sat

#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <drivers/behavior.h>

#include <zmk/behavior.h>
#include <zmk/rgb_underglow.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

/* param2 layout after conversion: bit 16 = converted flag,
 * bits 8-15 = brightness, bits 0-7 = saturation. */
#define RGB_HS_CONVERTED BIT(16)

static int rgb_hs_convert(struct zmk_behavior_binding *binding,
                          struct zmk_behavior_binding_event event) {
    if (binding->param2 & RGB_HS_CONVERTED) {
        return 0;
    }
    /* calc_brt(0) = current colour, brightness unchanged */
    struct zmk_led_hsb cur = zmk_rgb_underglow_calc_brt(0);
    binding->param2 = RGB_HS_CONVERTED | ((uint32_t)cur.b << 8) | (binding->param2 & 0xFF);
    return 0;
}

static int rgb_hs_pressed(struct zmk_behavior_binding *binding,
                          struct zmk_behavior_binding_event event) {
    struct zmk_led_hsb color;
    color.h = (uint16_t)(binding->param1 % 361);
    color.s = (uint8_t)MIN(binding->param2 & 0xFF, 100);

    if (binding->param2 & RGB_HS_CONVERTED) {
        color.b = (uint8_t)((binding->param2 >> 8) & 0xFF);
    } else {
        /* Not converted (e.g. non-split): use local brightness */
        color.b = zmk_rgb_underglow_calc_brt(0).b;
    }

    LOG_DBG("rgb_hs: h=%d s=%d b=%d", color.h, color.s, color.b);
    return zmk_rgb_underglow_set_hsb(color);
}

static int rgb_hs_released(struct zmk_behavior_binding *binding,
                           struct zmk_behavior_binding_event event) {
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_rgb_hue_sat_driver_api = {
    .binding_convert_central_state_dependent_params = rgb_hs_convert,
    .binding_pressed = rgb_hs_pressed,
    .binding_released = rgb_hs_released,
    .locality = BEHAVIOR_LOCALITY_GLOBAL,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL,
                        CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &behavior_rgb_hue_sat_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
