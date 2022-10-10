#include "lvgl/lvgl.h"
#include "ClockAlarmUI.h"
#include "glvgl_widget.h"
#include <stdlib.h>

typedef uint8_t lv_menu_builder_variant_t;


lv_obj_t* widget_create_mbox(lv_obj_t *parent, const char* title, const char* msg,const char* opts[],uint8_t close_btn)
{
    lv_obj_t* mbox = lv_msgbox_create(parent, title, msg, opts, close_btn);
    lv_obj_center(mbox);
    lv_obj_add_event_cb(mbox,event_handler_mbox, LV_EVENT_VALUE_CHANGED,NULL);
    return mbox;
}

lv_obj_t* widget_create_radio_btn(lv_obj_t* parent, const char* txt, lv_style_t * style_radio , lv_style_t* style_radio_chk)
{
    lv_obj_t* cb = lv_checkbox_create(parent);
    lv_checkbox_set_text(cb, txt);
    lv_obj_add_flag(cb, LV_OBJ_FLAG_EVENT_BUBBLE);
    return cb;
}

 lv_obj_t* widget_create_label(lv_obj_t* parent, const char* icon, const char* txt,
    lv_menu_builder_variant_t builder_variant)
{
    lv_obj_t* obj = lv_menu_cont_create(parent);

    lv_obj_t* img = NULL;
    lv_obj_t* label = NULL;

    if (icon) {
        img = lv_img_create(obj);
        lv_img_set_src(img, icon);
    }

    if (txt) {
        label = lv_label_create(obj);
        lv_label_set_text(label, txt);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
    }

    if (builder_variant == LV_MENU_ITEM_BUILDER_VARIANT_2 && icon && txt) {
        lv_obj_add_flag(img, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
        lv_obj_swap(img, label);
    }

    return obj;
}

 lv_obj_t* widget_create_switch(lv_obj_t* parent, const char* icon, const char* txt, bool chk, lv_event_cb_t event_cb)
{
    lv_obj_t* obj = widget_create_label(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_obj_t* sw = lv_switch_create(obj);
    lv_obj_add_state(sw, chk ? LV_STATE_CHECKED : 0);
    lv_obj_t* label = lv_obj_get_child(obj,1);
    lv_obj_add_event_cb(sw, event_cb,LV_EVENT_VALUE_CHANGED,(void*)label);
    return sw;
}

 lv_obj_t* widget_create_button(lv_obj_t* parent, const char* txt, lv_style_t* main, lv_style_t* pressed, lv_event_cb_t event_cb)
 {
     lv_obj_t* btn_obj = lv_btn_create(parent);
     lv_obj_remove_style_all(btn_obj);
     lv_obj_add_style(btn_obj, main, 0);
     lv_obj_add_style(btn_obj, pressed, LV_STATE_PRESSED);

     lv_obj_t* label = lv_label_create(btn_obj);
     lv_label_set_text(label, txt);
     lv_obj_center(label);

     lv_obj_add_event_cb(btn_obj,event_cb,LV_EVENT_CLICKED,NULL);

     return btn_obj;
 }

 lv_obj_t* widget_create_slider(lv_obj_t* parent, const char* icon, const char* txt, int32_t min, int32_t max, \
    int32_t val)
{
    lv_obj_t* obj = widget_create_label(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_2);

    lv_obj_t* slider = lv_slider_create(obj);
    lv_obj_set_flex_grow(slider, 1);
    lv_slider_set_range(slider, min, max);
    lv_slider_set_value(slider, val, LV_ANIM_OFF);

    if (icon == NULL) {
        lv_obj_add_flag(slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
    }

    return obj;
}

 lv_obj_t* widget_create_menu(lv_obj_t* parent, bool enable_root_btn, lv_event_cb_t event_cb)
 {
     lv_obj_t* menu = lv_menu_create(parent);
     if(enable_root_btn)
         lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
     lv_obj_add_event_cb(menu, event_cb, LV_EVENT_CLICKED, menu);
     return menu;
 }

 lv_obj_t* widget_create_calender(lv_obj_t* parent, calendar_data_t *data)
{
    lv_obj_t* calendar = lv_calendar_create(parent);
    lv_obj_set_size(calendar, 185, 185);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 27);
    lv_calendar_set_showed_date(calendar, data->year, data->month);
    lv_calendar_set_today_date(calendar, data->year, data->month, data->date);

#if LV_USE_CALENDAR_HEADER_DROPDOWN
    lv_calendar_header_dropdown_create(calendar);
#elif LV_USE_CALENDAR_HEADER_ARROW
    lv_calendar_header_arrow_create(calendar);
#endif
    lv_obj_add_event_cb(calendar, event_handler_date_change, LV_EVENT_VALUE_CHANGED, NULL);

    return calendar;
}

lv_obj_t* widget_create_roller(lv_obj_t* parent, const char* opts, int active_id)
{
    lv_obj_t* roller;
    /*A style to make the selected option larger*/
    static lv_style_t style_sel;
    lv_style_init(&style_sel);
    lv_style_set_text_font(&style_sel, &lv_font_montserrat_22);

    roller = lv_roller_create(parent);
    lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, 2);
    lv_roller_set_selected(roller,active_id, LV_ANIM_ON);
    lv_obj_set_height(roller, LV_PCT(100));
    lv_obj_set_width(roller, 80);
    lv_obj_add_style(roller, &style_sel, LV_PART_SELECTED);
    lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_LEFT, 0);

    return roller;

}

///////////////////////////////event handlers//////////////////////////////////////////////////

 void event_handler_root_back_btn(lv_event_t* e)
{
    lv_obj_t* obj = lv_event_get_target(e);
    lv_obj_t* menu = lv_event_get_user_data(e);
    if (lv_menu_back_btn_is_root(menu, obj)) {
        UI_event_t event;
        event.sig = E_ROOT_BACK;
        ClockAlarmUI_process_event(&ClockAlarmUI_inst,&event);
    }
}


 void event_handler_settings_time_format(lv_event_t* e)
{
    UI_time_change_event_t event;
    radio_btn_data *data = (radio_btn_data*)lv_event_get_user_data(e);
    uint32_t* active_id = &data->active_index_1;
    lv_obj_t* cont = lv_event_get_current_target(e);
    lv_obj_t* act_cb = lv_event_get_target(e);
    lv_obj_t* old_cb = lv_obj_get_child(cont, *active_id);

    /*Do nothing if the container was clicked*/
    if (act_cb == cont) return;

    uint32_t old_id = lv_obj_get_index(old_cb);

    lv_obj_clear_state(old_cb, LV_STATE_CHECKED);   /*Uncheck the previous radio button*/
    lv_obj_add_state(act_cb, LV_STATE_CHECKED);     /*Uncheck the current radio button*/

    *active_id = lv_obj_get_index(act_cb);

    LV_LOG_USER("Selected radio buttons: %d, %d", (int)*active_id, (int)old_id );
    if (data->setting_type == SETTING_TIME) {
            event.super.sig = E_SETTING_CLOCK_FORMAT;
    }
    else if (data->setting_type == SETTING_ALARM) {
            event.super.sig = E_SETTING_ALARM_FORMAT;
    }
    else {
        event.super.sig = E_NONE;
    }

    event.param = *active_id;
    ClockAlarmUI_process_event(&ClockAlarmUI_inst,&event.super);
}

static void delete_dropdwn_list(Lvgl* lvgl_inst)
{

    if (lvgl_inst->dropdwn_list != NULL) {
        lv_obj_del(lvgl_inst->dropdwn_list);
        lvgl_inst->dropdwn_list = NULL;
    }
}

 void event_handler_screen(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    Lvgl* const lvgl_inst = (Lvgl*)lv_event_get_user_data(e);
    if (code == LV_EVENT_PRESSED) {
        delete_dropdwn_list(lvgl_inst);
    }
    else
        LV_LOG_USER("Nothing to delete");

}

 void event_handler_dropdown_btn_opts_settings(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        UI_event_t event;
        event.sig = E_SETTING;
        ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
    }
}

 void event_handler_dropdown_btn_opts_about(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    Lvgl* const lvgl_inst = (Lvgl*)lv_event_get_user_data(e);
    delete_dropdwn_list(lvgl_inst);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_t* mbox1 = lv_msgbox_create(NULL, "About", "Clock version: 1.0\nBy FastBit EBA\nPowered by LVGL v8.3", NULL, true);
        lv_obj_center(mbox1);
    }
}


 void event_handler_dropdown_btn(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    Lvgl* const lvgl_inst = (Lvgl*)lv_event_get_user_data(e);
    lv_obj_t* btn;

    if (code == LV_EVENT_CLICKED) {
        lvgl_inst->dropdwn_list = lv_list_create(lvgl_inst->screen);
        btn = lv_list_add_btn(lvgl_inst->dropdwn_list, LV_SYMBOL_SETTINGS, "Settings");
        lv_obj_add_event_cb(btn, event_handler_dropdown_btn_opts_settings, LV_EVENT_CLICKED, (void*)lvgl_inst);
        btn = lv_list_add_btn(lvgl_inst->dropdwn_list, LV_SYMBOL_FILE, "About");
        lv_obj_add_event_cb(btn, event_handler_dropdown_btn_opts_about, LV_EVENT_CLICKED,(void*)lvgl_inst);
        lv_obj_set_height(lvgl_inst->dropdwn_list, LV_SIZE_CONTENT);
        lv_obj_align(lvgl_inst->dropdwn_list, LV_ALIGN_TOP_RIGHT, 0, 0);
    }
}

 void event_handler_mbox(lv_event_t* e)
 {
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* mbox;
     UI_generic_event_t event;
     if (code == LV_EVENT_VALUE_CHANGED)
     {
         mbox = lv_event_get_current_target(e);
         int btn_id = lv_msgbox_get_active_btn(mbox);
         lv_msgbox_close(mbox);
         event.super.sig = E_SETTING_SAVE_YES_NO;
         event.param = btn_id;
         ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);
     }
 }

 void event_handler_date_change(lv_event_t* e)
 {
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_current_target(e);
     lv_calendar_t* calendar = (lv_calendar_t*)obj;
     lv_calendar_date_t date;
     UI_date_change_event_t event;
     if (code == LV_EVENT_VALUE_CHANGED) {
         if (lv_calendar_get_pressed_date(obj, &date)) {
             int i = lv_btnmatrix_get_selected_btn(calendar->btnm);
             lv_btnmatrix_clear_btn_ctrl_all(calendar->btnm, LV_BTNMATRIX_CTRL_CUSTOM_2);
             lv_btnmatrix_set_btn_ctrl(calendar->btnm, i, LV_BTNMATRIX_CTRL_CUSTOM_2);
             LV_LOG_USER("Clicked date: %02d.%02d.%d %d", date.day, date.month, date.year, i);
             event.super.sig = E_SETTING_DATE_CHANGE;
             event.date = date.day;
             event.month = date.month;
             event.year = date.year;
             ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);
         }
     }
 }

 void event_handler_time_rollers(lv_event_t* e) {
     uint8_t roller_value;
     event_t sig;
     UI_time_change_event_t event;

     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     roller_data* data = (roller_data*)lv_event_get_user_data(e);
     if (code == LV_EVENT_VALUE_CHANGED) {
         char str[3];
         lv_roller_get_selected_str(obj, str, sizeof(str));
         roller_value = atoi(str);
       
        if (data->roller_type == ROLLER_HOUR) {
            sig = E_SETTING_CLOCK_HOUR;
        }
        else if (data->roller_type == ROLLER_MIN) {
            sig = E_SETTING_CLOCK_MIN;
        }
        else if (data->roller_type == ROLLER_SEC) {
            sig = E_SETTING_CLOCK_SEC;
        }
        else
            sig = E_NONE;
        event.super.sig = sig;
        event.param = roller_value;
        ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);
        
     }
 }
 void event_handler_alarm_rollers(lv_event_t* e) {
     uint8_t roller_value;
     event_t sig;
     UI_time_change_event_t event;

     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     roller_data* data = (roller_data*)lv_event_get_user_data(e);
     if (code == LV_EVENT_VALUE_CHANGED) {
         char str[3];
         lv_roller_get_selected_str(obj, str, sizeof(str));
         roller_value = atoi(str);
             if (data->roller_type == ROLLER_HOUR) {
                 sig = E_SETTING_ALARM_HOUR;
             }
             else if (data->roller_type == ROLLER_MIN) {
                 sig = E_SETTING_ALARM_MIN;
             }
             else
                 sig = E_NONE;
             event.super.sig = sig;
             event.param = roller_value;
             ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);
         

     }
 }

 void event_handler_date_save(lv_event_t* e)
 {
     UI_event_t event;
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     if (code == LV_EVENT_CLICKED) {
         event.sig = E_DATE_SAVE;
         ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
     }
     UNUSED(obj);
 }


 void event_handler_time_save(lv_event_t* e)
 {
     UI_event_t event;
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     if (code == LV_EVENT_CLICKED) {
         event.sig = E_CLOCK_SAVE;
         ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
     }
     UNUSED(obj);
 }


 void event_handler_alarm_save(lv_event_t* e)
 {
     UI_event_t event;
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     if (code == LV_EVENT_CLICKED) {
         event.sig = E_ALARM_SAVE;
         ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
     }
     UNUSED(obj);
 }

 void event_handler_switch_sound(lv_event_t* e)
 {
   
 }


 void event_handler_switch_24h(lv_event_t* e)
 {
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     UI_time_change_event_t event;
     bool state = lv_obj_has_state(obj, LV_STATE_CHECKED);
     event.super.sig = E_SETTING_CLOCK_MODE;
     if (state) {
         //24h
         event.param = MODE_24H;
     }
     else {
         //12h
         event.param = MODE_12H;
     }
     ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);

     UNUSED(code);
 }

 void event_handler_switch_alarm(lv_event_t* e)
 {
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     UI_time_change_event_t event;
     bool state = lv_obj_has_state(obj, LV_STATE_CHECKED);
     event.super.sig = E_ALARM_ON_OFF;
     lv_obj_t* label = lv_event_get_user_data(e);
     if (state) {
         //alarm on 
         lv_label_set_text(label, "Alarm:ON");
         event.param = ALARM_ON;
     }
     else {
         //alarm off
         lv_label_set_text(label, "Alarm:OFF");
         event.param = ALARM_OFF;
     }
     ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event.super);
     UNUSED(code);
 }


 void event_handler_alarm_notif_close(lv_event_t* e)
 {
     UI_event_t event;
     lv_event_code_t code = lv_event_get_code(e);
     lv_obj_t* obj = lv_event_get_target(e);
     if (code == LV_EVENT_CLICKED) {
         event.sig = E_ALARM_NOTIF_CLOSE;
         ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
     }
     UNUSED(obj);
 }
