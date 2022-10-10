#ifndef GLVGL_WID_H
#define GLVGL_WID_H
#include "glvgl.h"

typedef uint8_t lv_menu_builder_variant_t;

enum roller_type {
    ROLLER_HOUR,
    ROLLER_MIN,
    ROLLER_SEC
 };

enum setting_type {
    SETTING_TIME,
    SETTING_ALARM
};

typedef struct {
    uint8_t roller_type;
    uint8_t setting_type;
    int roller_active_id;
}roller_data;

typedef struct {
    uint8_t setting_type;
    uint32_t active_index_1;
    uint32_t active_index_2;
    int active_id;
}radio_btn_data;

typedef struct
{
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint8_t date;
}calendar_data_t;

#ifdef __cplusplus
extern "C" {
#endif
lv_obj_t* widget_create_radio_btn(lv_obj_t* parent, const char* txt, lv_style_t* style_radio,\
                                    lv_style_t* style_radio_chk);
lv_obj_t* widget_create_label(lv_obj_t* parent, const char* icon, const char* txt, \
                                    lv_menu_builder_variant_t builder_variant);
lv_obj_t* widget_create_switch(lv_obj_t* parent, const char* icon, const char* txt, bool chk, lv_event_cb_t event_cb);
lv_obj_t* widget_create_slider(lv_obj_t* parent, const char* icon, const char* txt, \
                                    int32_t min, int32_t max, int32_t val);
lv_obj_t* widget_create_calender(lv_obj_t* parent, calendar_data_t* data);
lv_obj_t* widget_create_roller(lv_obj_t* parent, const char* opts, int active_id);
lv_obj_t* widget_create_mbox(lv_obj_t* parent, const char* title, const char* msg, const char* opts[], uint8_t close_btn);
lv_obj_t* widget_create_button(lv_obj_t* parent, const char* txt,lv_style_t *normal, lv_style_t *pressed, lv_event_cb_t event_cb);
lv_obj_t* widget_create_menu(lv_obj_t* parent, bool enable_root_btn, lv_event_cb_t event_cb);

void event_handler_dropdown_btn(lv_event_t* e);
void event_handler_dropdown_btn_opts_about(lv_event_t* e);
void event_handler_dropdown_btn_opts_settings(lv_event_t* e);
void event_handler_screen(lv_event_t* e);
void event_handler_settings_time_format(lv_event_t* e);
void event_handler_root_back_btn(lv_event_t* e);
void event_handler_time_rollers(lv_event_t* e);
void event_handler_alarm_rollers(lv_event_t* e);
void event_handler_mbox(lv_event_t* e);
void event_handler_date_change(lv_event_t* e);
void event_handler_date_save(lv_event_t* e);
void event_handler_time_save(lv_event_t* e);
void event_handler_alarm_save(lv_event_t* e);
void event_handler_switch_24h(lv_event_t* e);
void event_handler_switch_alarm(lv_event_t* e);
void event_handler_switch_sound(lv_event_t* e);
void event_handler_alarm_notif_close(lv_event_t* e);

#ifdef __cplusplus
}
#endif

#endif
