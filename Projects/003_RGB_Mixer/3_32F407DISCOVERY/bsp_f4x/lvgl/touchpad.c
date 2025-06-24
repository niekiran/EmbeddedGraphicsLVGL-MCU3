/**
 * @file indev.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "tft.h"
#include "lvgl/lvgl.h"

#include "stm32f4xx.h"
#include "XPT2046.h"
#include "FT6336U.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize your input devices here
 */
void touchpad_init(void)
{
  //stmpe811_Init(TS_I2C_ADDRESS);
 // stmpe811_TS_Start(TS_I2C_ADDRESS);
#if USE_FT6336U
  ft6336u_init();
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.read_cb = ft6336u_read;
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  lv_indev_drv_register(&indev_drv);
#elif USE_XPT2046
  xpt2046_init();
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.read_cb = xpt2046_read;
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  lv_indev_drv_register(&indev_drv);
#endif
}


