#include "glvgl.h"
#include "lvgl/lvgl.h"
#include "ClockAlarmUI.h"
#include "glvgl_widget.h"
#include <stdio.h>

static void create_time_date_header(Lvgl* const me);
static void create_time_format(lv_obj_t* parent, radio_btn_data* data);
static lv_obj_t* create_settings_time_alarm_rollers(lv_obj_t* parent, roller_data* h, roller_data* m, roller_data* s, \
    lv_event_cb_t event_cb);

void Lvgl_display_clock(Lvgl * const me, char *const time_as_string) {
    lv_label_set_text_fmt(me->clock,"%s",time_as_string);
}

void Lvgl_btn_style_init(Lvgl* const me) {

    lv_style_init(&me->style_btn_normal);
    lv_style_init(&me->style_btn_clicked);

    lv_style_set_radius(&me->style_btn_normal, 3);
    lv_style_set_bg_opa(&me->style_btn_normal, LV_OPA_100);
    lv_style_set_bg_color(&me->style_btn_normal, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_opa(&me->style_btn_normal, LV_OPA_40);
    lv_style_set_border_width(&me->style_btn_normal, 2);
    lv_style_set_border_color(&me->style_btn_normal, lv_palette_main(LV_PALETTE_GREY));


    lv_style_set_outline_opa(&me->style_btn_normal, LV_OPA_COVER);
    lv_style_set_outline_color(&me->style_btn_normal, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_text_color(&me->style_btn_normal, lv_color_white());
    lv_style_set_pad_all(&me->style_btn_normal, 10);


    /*Add a large outline when pressed*/
    lv_style_set_outline_width(&me->style_btn_clicked, 30);
    lv_style_set_outline_opa(&me->style_btn_clicked, LV_OPA_TRANSP);

    lv_style_set_translate_y(&me->style_btn_clicked, 5);
    lv_style_set_bg_color(&me->style_btn_clicked, lv_palette_darken(LV_PALETTE_BLUE, 2));
    lv_style_set_bg_grad_color(&me->style_btn_clicked, lv_palette_darken(LV_PALETTE_BLUE, 4));

    /*Add a transition to the outline*/
    static lv_style_transition_dsc_t trans;
    static lv_style_prop_t props[] = { LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0 };
    lv_style_transition_dsc_init(&trans, props, lv_anim_path_linear, 300, 0, NULL);

    lv_style_set_transition(&me->style_btn_clicked, &trans);

}

void Lvgl_main_page_set_style(Lvgl* const me)
{
    lv_obj_set_style_bg_color(me->screen, lv_palette_main(LV_PALETTE_AMBER), LV_PART_MAIN);

    /*Clock*/
    lv_obj_set_style_text_font(me->clock, &lv_font_montserrat_40, LV_PART_MAIN);
    /*Date*/
    lv_obj_set_style_text_font(me->day, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_font(me->month, &lv_font_montserrat_12, LV_PART_MAIN);
    lv_obj_set_style_text_font(me->date, &lv_font_montserrat_40, LV_PART_MAIN);
    lv_obj_set_style_text_font(me->year, &lv_font_montserrat_12, LV_PART_MAIN);

    /*Add main page allignment code here */
    lv_obj_align(me->clock, LV_ALIGN_TOP_RIGHT, LV_PCT(-5), LV_PCT(40));
    lv_obj_align(me->date, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(40));
    lv_obj_align(me->day, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(35));
    lv_obj_align(me->month, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(30));
    lv_obj_align(me->year, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(55));

    /*dropdown btn setup*/
    lv_obj_remove_style_all(me->dropdwn_btn);
    lv_obj_set_size(me->dropdwn_btn, 30, 30);
    lv_obj_align(me->dropdwn_btn, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_opa(me->dropdwn_btn, LV_OPA_90, LV_STATE_PRESSED);
    lv_obj_set_style_radius(me->dropdwn_btn, 5, LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(me->dropdwn_btn, lv_palette_main(LV_PALETTE_AMBER), LV_STATE_PRESSED);
    lv_obj_t* label = lv_label_create(me->dropdwn_btn);
    lv_label_set_text(label, LV_SYMBOL_LIST);
    lv_obj_set_style_text_color(label, lv_color_black(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, LV_PART_MAIN);
    lv_obj_center(label);
}

void Lvgl_display_day(Lvgl * const me, const char *const day) {
    lv_label_set_text_static(me->day,day);
}

void Lvgl_display_month(Lvgl * const me, const char *const month) {
    lv_label_set_text_static(me->month, month);
}

void Lvgl_display_calendar_date(Lvgl* const me, uint8_t date, uint8_t month , uint32_t year)
{
    lv_label_set_text_fmt(me->date, "%d/%d/%ld", date,month,year);
}
void Lvgl_display_date(Lvgl * const me, uint8_t date) {
    lv_label_set_text_fmt(me->date, "%d",date);
}

void Lvgl_display_year(Lvgl * const me, uint32_t year) {
    lv_label_set_text_fmt(me->year, "%ld", year);
}

void Lvgl_create_message_box(Lvgl* const me, const char* title, const char* msg, const char* opts[], bool close_btn)
{
    widget_create_mbox(NULL, title, msg, opts, close_btn);
}

void Lvgl_create_main_page(Lvgl * const me) {

    /*Clock*/
    me->clock = lv_label_create(me->screen);

    /*Date*/
    me->day = lv_label_create(me->screen);
    me->month = lv_label_create(me->screen);
    me->date = lv_label_create(me->screen);
    me->year = lv_label_create(me->screen);

    me->dropdwn_btn = lv_btn_create(me->screen);
   
    lv_obj_add_event_cb(me->screen, event_handler_screen, LV_EVENT_PRESSED, (void*)me);
    lv_obj_add_event_cb(me->dropdwn_btn, event_handler_dropdown_btn, LV_EVENT_CLICKED, (void*)me);
   
}


void Lvgl_style_init(Lvgl* const me)
{
    lv_style_init(&me->style_clock);
    Lvgl_btn_style_init(me);
}

void Lvgl_create_alarm_notif_page(Lvgl* const me, lvgl_alarm_page_data_t *data) {

    create_time_date_header(me);

    LV_IMG_DECLARE(alarm_gif_new);
    lv_obj_t* img;
    img = lv_gif_create(me->screen);
    lv_gif_set_src(img, &alarm_gif_new);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* close_btn = widget_create_button(me->screen, "Close", &me->style_btn_normal, &me->style_btn_clicked, event_handler_alarm_notif_close);
    lv_obj_align_to(close_btn,img,LV_ALIGN_OUT_BOTTOM_MID,0,10);
}



void Lvgl_create_setting_page(Lvgl * const me, lvgl_setting_page_data_t* data) {
    lv_obj_t* root_page;
    lv_obj_t* cont;
    lv_obj_t* default_cont_to_show;
    lv_obj_t* section;
    lv_obj_t* parent_row;
    lv_obj_t* menu;


    create_time_date_header(me);
   
    menu = widget_create_menu(me->screen,true, event_handler_root_back_btn);
    lv_color_t bg_color = lv_obj_get_style_bg_color(menu, 0);
    if (lv_color_brightness(bg_color) > 127) {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 10), 0);
    }
    else {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 50), 0);
    }
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL) - 20);
    lv_obj_align(menu, LV_ALIGN_BOTTOM_MID, 0, 0);

    /*Create sub pages*/
    ///////////////Create DATE page//////////////////////////////
    lv_obj_t* date_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(date_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(date_page);
    calendar_data_t cal_data;
    cal_data.date = data->date;
    cal_data.day = data->day;
    cal_data.month = data->month;
    cal_data.year = data->year;
    widget_create_calender(date_page,&cal_data);
    lv_menu_separator_create(date_page);
    widget_create_button(date_page,"Save",&me->style_btn_normal,&me->style_btn_clicked,event_handler_date_save);
    ///////////////End Create DATE page//////////////////////////////

    ///////////////Create Time page//////////////////////////////
    lv_obj_t* time_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(time_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(time_page);
    section = lv_menu_section_create(time_page);
    static roller_data time_h, time_m, time_s;
    time_h.roller_active_id = data->clock_hour - 1;
    time_m.roller_active_id = data->clock_min;
    time_s.roller_active_id = data->clock_sec;
    parent_row = create_settings_time_alarm_rollers(section, &time_h, &time_m, &time_s,event_handler_time_rollers);
    static radio_btn_data time_format;
    time_format.setting_type = SETTING_TIME;
    if (data->clock_format == FORMAT_AM) {
        time_format.active_id = 0;
    }
    else if (data->clock_format == FORMAT_PM) {
        time_format.active_id = 1;
    }
    time_format.active_index_1 = time_format.active_id;
    create_time_format(parent_row, &time_format);

    lv_menu_separator_create(time_page);
    section = lv_menu_section_create(time_page);
    lv_obj_t *sw = widget_create_switch(section, LV_SYMBOL_SETTINGS, "24H", false,event_handler_switch_24h);

    if (data->clock_mode == MODE_12H) {
        lv_obj_add_state(sw,0);
    }
    else if (data->clock_mode == MODE_24H) {
        lv_obj_add_state(sw, LV_STATE_CHECKED);
    }

    lv_menu_separator_create(time_page);
    widget_create_button(time_page, "Save", &me->style_btn_normal, &me->style_btn_clicked,event_handler_time_save);
    ///////////////End of create Time page//////////////////////////////

    //////////////////////Create Alarm page///////////////////////////
    lv_obj_t* alarm_page = lv_menu_page_create(menu, NULL);
    static roller_data alarm_h, alarm_m;
    alarm_h.roller_active_id = data->alarm_hour - 1;
    alarm_m.roller_active_id = data->alarm_min;
    lv_obj_set_style_pad_hor(alarm_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(alarm_page);
    section = lv_menu_section_create(alarm_page);
    parent_row = create_settings_time_alarm_rollers(section, &alarm_h, &alarm_m,NULL, event_handler_alarm_rollers);
    static radio_btn_data alarm_format;
    alarm_format.setting_type = SETTING_ALARM;
    if (data->alarm_format == FORMAT_AM) {
        alarm_format.active_id = 0;
    }
    else if (data->alarm_format == FORMAT_PM) {
        alarm_format.active_id = 1;
    }
    alarm_format.active_index_1 = alarm_format.active_id;
    create_time_format(parent_row, &alarm_format);

    char* status;
    bool alarm_check;
    if (data->alarm_status == ALARM_ON) {
        status = "Alarm:ON";
        alarm_check = true;
    }
    else {
        status = "Alarm:OFF";
        alarm_check = false;
    }
    lv_menu_separator_create(alarm_page);
    section = lv_menu_section_create(alarm_page);
    widget_create_switch(section, LV_SYMBOL_BELL, status, alarm_check,event_handler_switch_alarm);

    lv_menu_separator_create(alarm_page);
    widget_create_button(alarm_page, "Save", &me->style_btn_normal, &me->style_btn_clicked,event_handler_alarm_save);
    //////////////////////End create Alarm page///////////////////////////

    //////////////////////Create Sound page///////////////////////////
    lv_obj_t* sound_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sound_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sound_page);
    section = lv_menu_section_create(sound_page);
    widget_create_switch(section, LV_SYMBOL_AUDIO, "Sound", false,event_handler_switch_sound);
    //////////////////////End create Sound page///////////////////////////

    //////////////////////Create Display page///////////////////////////
    lv_obj_t* display_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(display_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(display_page);
    section = lv_menu_section_create(display_page);
    widget_create_slider(section, LV_SYMBOL_SETTINGS, "Brightness", 0, 150, 100);
    //////////////////////End create Display page///////////////////////////

    //////////////////////Create Root page///////////////////////////
    root_page = lv_menu_page_create(menu, "Settings");
    section = lv_menu_section_create(root_page);
    cont = widget_create_label(section, LV_SYMBOL_SETTINGS, "Date", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont,date_page);
    default_cont_to_show = cont;
    cont = widget_create_label(section, LV_SYMBOL_SETTINGS, "Time", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, time_page);
    cont = widget_create_label(section, LV_SYMBOL_SETTINGS, "Alarm", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, alarm_page);
    cont = widget_create_label(section, LV_SYMBOL_AUDIO, "Sound", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sound_page);
    cont = widget_create_label(section, LV_SYMBOL_SETTINGS, "Display", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, display_page);

    /*Set the 'Root page' as sidebar page*/
    lv_menu_set_sidebar_page(menu, root_page);

    /*Send event manually to 'default_cont_to_show'*/
    lv_event_send(default_cont_to_show, LV_EVENT_CLICKED, NULL);
    // lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
    
}

void Lvgl_screen_cleanup(Lvgl * const me) {
    lv_obj_clean(me->screen);
    me->dropdwn_list = NULL;
}

void Lvgl_ctor(Lvgl *const me) {
    me->screen = lv_scr_act();
    Lvgl_style_init(me);

}

static void create_time_date_header(Lvgl* const me) {
    me->clock = lv_label_create(me->screen);
    lv_label_set_text(me->clock, "");
    lv_obj_set_style_text_font(me->clock, &lv_font_montserrat_14, 0);
    lv_obj_align(me->clock, LV_ALIGN_TOP_RIGHT, -5, 0);

    me->date = lv_label_create(me->screen);
    lv_label_set_text(me->date, "");
    lv_obj_set_style_text_font(me->date, &lv_font_montserrat_14, 0);
    lv_obj_align(me->date, LV_ALIGN_TOP_LEFT, 5, 0);
}

static void create_time_format(lv_obj_t* parent, radio_btn_data* data)
{
    lv_obj_t* cont_col = lv_obj_create(parent);
    lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_width(cont_col, LV_SIZE_CONTENT);
    lv_obj_set_height(cont_col, LV_SIZE_CONTENT);

    lv_obj_add_event_cb(cont_col, event_handler_settings_time_format, LV_EVENT_CLICKED, data);

    widget_create_radio_btn(cont_col, "AM", NULL, NULL);
    widget_create_radio_btn(cont_col, "PM", NULL, NULL);
    lv_obj_add_state(lv_obj_get_child(cont_col, data->active_id), LV_STATE_CHECKED);
}


static lv_obj_t* create_settings_time_alarm_rollers(lv_obj_t* parent, roller_data* h, roller_data* m, roller_data* s, lv_event_cb_t event_cb)
{
    const char* opts_h = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";

    const char* opts_m_s = "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12 \
                          \n13\n14\n15\n16\n17\n18\n19\n20\n21\n22      \
                          \n23\n24\n25\n26\n27\n28\n29\n30\n31\n32      \
                          \n33\n34\n35\n36\n37\n38\n39\n40\n41\n42      \
                          \n43\n44\n45\n46\n47\n48\n49\n50\n51\n52      \
                          \n53\n54\n55\n56\n57\n58\n59";


    lv_obj_t* roller_h;
    lv_obj_t* roller_m;
    lv_obj_t* roller_s;

    lv_obj_t* cont_row = lv_obj_create(parent);
    lv_obj_set_size(cont_row, LV_SIZE_CONTENT, 100);
    lv_obj_set_flex_flow(cont_row, LV_FLEX_FLOW_ROW);

    lv_obj_t* label_h = lv_label_create(cont_row);
    lv_label_set_text(label_h, "hh");
    roller_h = widget_create_roller(cont_row, opts_h, h->roller_active_id);
    h->roller_type = ROLLER_HOUR;
    lv_obj_add_event_cb(roller_h, event_cb, LV_EVENT_VALUE_CHANGED, h);

    lv_obj_t* label_m = lv_label_create(cont_row);
    lv_label_set_text(label_m, "mm");
    roller_m = widget_create_roller(cont_row, opts_m_s, m->roller_active_id);
    m->roller_type = ROLLER_MIN;
    lv_obj_add_event_cb(roller_m, event_cb, LV_EVENT_VALUE_CHANGED, m);

    if (s != NULL) {
        lv_obj_t* label_s = lv_label_create(cont_row);
        lv_label_set_text(label_s, "ss");
        roller_s = widget_create_roller(cont_row, opts_m_s, s->roller_active_id);
        s->roller_type = ROLLER_SEC;
        lv_obj_add_event_cb(roller_s, event_cb, LV_EVENT_VALUE_CHANGED, s);

    }


    return cont_row;
}
