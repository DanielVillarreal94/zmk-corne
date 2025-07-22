#include <lvgl.h>

// Logo principal del Corne
static const uint8_t corne_logo_data[] = {
    // Datos generados por la herramienta - ejemplo
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3E, 0x7C, 0x7E, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x61, 0x86, 0x61, 0x83, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // ... más datos (completar con la herramienta)
};

LV_IMG_DECLARE(corne_logo);
const lv_img_dsc_t corne_logo = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(corne_logo_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = corne_logo_data,
};

// Imagen para capa default
static const uint8_t layer_default_data[] = {
    // Datos para mostrar "DEFAULT" o un icono
    // Generar con la herramienta
};

LV_IMG_DECLARE(layer_default);
const lv_img_dsc_t layer_default = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(layer_default_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layer_default_data,
};

// Imagen para capa lower
static const uint8_t layer_lower_data[] = {
    // Datos para mostrar "LOWER" o un icono de navegación
};

LV_IMG_DECLARE(layer_lower);
const lv_img_dsc_t layer_lower = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(layer_lower_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layer_lower_data,
};

// Imagen para capa raise
static const uint8_t layer_raise_data[] = {
    // Datos para mostrar "SYMBOLS" o iconos de símbolos
};

LV_IMG_DECLARE(layer_raise);
const lv_img_dsc_t layer_raise = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(layer_raise_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layer_raise_data,
};

// Imagen para capa numbers
static const uint8_t layer_numbers_data[] = {
    // Datos para mostrar "NUMBERS" o iconos numéricos
};

LV_IMG_DECLARE(layer_numbers);
const lv_img_dsc_t layer_numbers = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(layer_numbers_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layer_numbers_data,
};

// Imagen para capa bluetooth
static const uint8_t layer_bluetooth_data[] = {
    // Datos para mostrar "BLUETOOTH" o icono BT
};

LV_IMG_DECLARE(layer_bluetooth);
const lv_img_dsc_t layer_bluetooth = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(layer_bluetooth_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layer_bluetooth_data,
};

// Imágenes de batería
static const uint8_t battery_100_data[] = {
    // Batería llena
};

LV_IMG_DECLARE(battery_100);
const lv_img_dsc_t battery_100 = {
    .header.always_zero = 0,
    .header.w = 32,
    .header.h = 16,
    .data_size = sizeof(battery_100_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = battery_100_data,
};

static const uint8_t battery_75_data[] = {
    // Batería 75%
};

LV_IMG_DECLARE(battery_75);
const lv_img_dsc_t battery_75 = {
    .header.always_zero = 0,
    .header.w = 32,
    .header.h = 16,
    .data_size = sizeof(battery_75_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = battery_75_data,
};

static const uint8_t battery_50_data[] = {
    // Batería 50%
};

LV_IMG_DECLARE(battery_50);
const lv_img_dsc_t battery_50 = {
    .header.always_zero = 0,
    .header.w = 32,
    .header.h = 16,
    .data_size = sizeof(battery_50_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = battery_50_data,
};

static const uint8_t battery_25_data[] = {
    // Batería 25%
};

LV_IMG_DECLARE(battery_25);
const lv_img_dsc_t battery_25 = {
    .header.always_zero = 0,
    .header.w = 32,
    .header.h = 16,
    .data_size = sizeof(battery_25_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = battery_25_data,
};

static const uint8_t battery_10_data[] = {
    // Batería baja
};

LV_IMG_DECLARE(battery_10);
const lv_img_dsc_t battery_10 = {
    .header.always_zero = 0,
    .header.w = 32,
    .header.h = 16,
    .data_size = sizeof(battery_10_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = battery_10_data,
};

// Imágenes de Bluetooth
static const uint8_t bluetooth_connected_data[] = {
    // Icono BT conectado
};

LV_IMG_DECLARE(bluetooth_connected);
const lv_img_dsc_t bluetooth_connected = {
    .header.always_zero = 0,
    .header.w = 16,
    .header.h = 16,
    .data_size = sizeof(bluetooth_connected_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = bluetooth_connected_data,
};

static const uint8_t bluetooth_disconnected_data[] = {
    // Icono BT desconectado
};

LV_IMG_DECLARE(bluetooth_disconnected);
const lv_img_dsc_t bluetooth_disconnected = {
    .header.always_zero = 0,
    .header.w = 16,
    .header.h = 16,
    .data_size = sizeof(bluetooth_disconnected_data),
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = bluetooth_disconnected_data,
};
