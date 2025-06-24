/**
 * @file FT6336U.h
 *
 */

#ifndef FT6336U_H
#define FT6336U_H

#define USE_FT6336U 1

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "lv_drv_conf.h"
#endif
#endif

#if USE_FT6336U

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

/*********************
 *      DEFINES
 *********************/
#define FT6336U_I2C_ADDRESS     0x38  // 7-bit I2C address of FT6336U
#define FT6336U_MAX_POINTS      8     // Maximum number of touch points supported
#define FT6336U_AVG             2     // Number of samples for averaging

/* Touch coordinate calibration */
#define FT6336U_X_MIN           0     // Minimum X coordinate (raw)
#define FT6336U_X_MAX           480   // Maximum X coordinate (raw, adjust to display)
#define FT6336U_Y_MIN           0     // Minimum Y coordinate (raw)
#define FT6336U_Y_MAX           320   // Maximum Y coordinate (raw, adjust to display)
#define FT6336U_HOR_RES         480   // Display horizontal resolution
#define FT6336U_VER_RES         320   // Display vertical resolution
#define FT6336U_XY_SWAP         0     // Set to 1 to swap X and Y coordinates
#define FT6336U_X_INV           0     // Set to 1 to invert X axis
#define FT6336U_Y_INV           0     // Set to 1 to invert Y axis

/* FT6336U register addresses */
#define REG_ID_G_CIPHER_LOW     0xA3  // Chip ID register
#define REG_MODE_SWITCH         0x00  // Mode switch register
#define REG_G_MODE              0xA4  // Interrupt mode register
#define REG_TD_STATUS           0x02  // Touch status register
#define REG_P1_XH               0x03  // First touch point X high byte
#define CHIP_CODE_FT6336U       0x64  // Expected chip ID for FT6336U
#define REG_PERIOD_ACTIVE       0x88  // Touch sampling rate register
#define REG_TH_GROUP            0x80  // Touch sensitivity threshold register

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    I2C_HandleTypeDef *hi2c;
    GPIO_TypeDef *rst_port;
    uint16_t rst_pin;
    GPIO_TypeDef *int_port;
    uint16_t int_pin;
} ft6336u_handle_t;

typedef struct {
    uint16_t x;
    uint16_t y;
    uint8_t valid;
} touch_point_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void ft6336u_init(void);
uint8_t ft6336u_irq_pin_read(void);
void ft6336u_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
HAL_StatusTypeDef ft6336u_config(ft6336u_handle_t *hft, I2C_HandleTypeDef *hi2c,
                               GPIO_TypeDef *rst_port, uint16_t rst_pin,
                               GPIO_TypeDef *int_port, uint16_t int_pin);
HAL_StatusTypeDef ft6336u_read_touch(ft6336u_handle_t *hft, touch_point_t *points, uint8_t max_points);

/**********************
 *      MACROS
 **********************/

#endif /* USE_FT6336U */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* FT6336U_H */
