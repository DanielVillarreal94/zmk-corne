#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/logging/log.h>

#include <zmk/display.h>
#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/keymap.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);
static lv_obj_t *screen;

// Imágenes personalizadas (generadas con la herramienta)
LV_IMG_DECLARE(corne_logo);
LV_IMG_DECLARE(layer_default);
LV_IMG_DECLARE(layer_lower);
LV_IMG_DECLARE(layer_raise);
LV_IMG_DECLARE(layer_numbers);
LV_IMG_DECLARE(layer_bluetooth);
LV_IMG_DECLARE(battery_100);
LV_IMG_DECLARE(battery_75);
LV_IMG_DECLARE(battery_50);
LV_IMG_DECLARE(battery_25);
LV_IMG_DECLARE(battery_10);
LV_IMG_DECLARE(bluetooth_connected);
LV_IMG_DECLARE(bluetooth_disconnected);

static lv_obj_t *layer_image;
static lv_obj_t *battery_image;
static lv_obj_t *bt_image;
static lv_obj_t *status_text;

// Array de imágenes por capa
static const lv_img_dsc_t *layer_images[] = {
    &layer_default,    // Layer 0
    &layer_lower,      // Layer 1
    &layer_raise,      // Layer 2
    &layer_numbers,    // Layer 3
    &layer_bluetooth   // Layer 4
};

// Array de imágenes de batería
static const lv_img_dsc_t *battery_images[] = {
    &battery_10,   // 0-20%
    &battery_25,   // 21-40%
    &battery_50,   // 41-70%
    &battery_75,   // 71-90%
    &battery_100   // 91-100%
};

static void update_layer_display(uint8_t layer_index) {
    if (layer_index < ARRAY_SIZE(layer_images)) {
        lv_img_set_src(layer_image, layer_images[layer_index]);
    }
}

static void update_battery_display(uint8_t battery_level) {
    uint8_t image_index;
    
    if (battery_level > 90) image_index = 4;
    else if (battery_level > 70) image_index = 3;
    else if (battery_level > 40) image_index = 2;
    else if (battery_level > 20) image_index = 1;
    else image_index = 0;
    
    lv_img_set_src(battery_image, battery_images[image_index]);
}

static void update_bluetooth_display(bool connected) {
    if (connected) {
        lv_img_set_src(bt_image, &bluetooth_connected);
    } else {
        lv_img_set_src(bt_image, &bluetooth_disconnected);
    }
}

static int zmk_widget_status_init(const struct device *dev) {
    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), LV_PART_MAIN);
    
    // Logo principal (se muestra al inicio)
    lv_obj_t *logo = lv_img_create(screen);
    lv_img_set_src(logo, &corne_logo);
    lv_obj_align(logo, LV_ALIGN_TOP_MID, 0, 0);
    
    // Indicador de capa
    layer_image = lv_img_create(screen);
    lv_img_set_src(layer_image, &layer_default);
    lv_obj_align(layer_image, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    
    // Indicador de batería
    battery_image = lv_img_create(screen);
    lv_img_set_src(battery_image, &battery_100);
    lv_obj_align(battery_image, LV_ALIGN_BOTTOM_MID, 0, 0);
    
    // Indicador de Bluetooth
    bt_image = lv_img_create(screen);
    lv_img_set_src(bt_image, &bluetooth_disconnected);
    lv_obj_align(bt_image, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    
    // Texto de estado
    status_text = lv_label_create(screen);
    lv_label_set_text(status_text, "READY");
    lv_obj_set_style_text_color(status_text, lv_color_white(), LV_PART_MAIN);
    lv_obj_align(status_text, LV_ALIGN_CENTER, 0, 10);
    
    lv_scr_load(screen);
    return 0;
}

static int zmk_widget_status_listener(const zmk_event_t *eh) {
    if (as_zmk_layer_state_changed(eh)) {
        uint8_t layer = zmk_keymap_highest_layer_active();
        update_layer_display(layer);
        return 0;
    }
    
    if (as_zmk_battery_state_changed(eh)) {
        const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);
        update_battery_display(ev->state_of_charge);
        return 0;
    }
    
    return 0;
}

ZMK_LISTENER(widget_status, zmk_widget_status_listener);
ZMK_SUBSCRIPTION(widget_status, zmk_layer_state_changed);
ZMK_SUBSCRIPTION(widget_status, zmk_battery_state_changed);

SYS_INIT(zmk_widget_status_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
