
#include"lvgl/lvgl.h"

enum { SLIDER_R = 0, SLIDER_G, SLIDER_B };

typedef struct {
    uint8_t slider_type;
    lv_obj_t* label;
}rgb_mixer_t;

lv_obj_t* rect;

void slider_callback(lv_event_t* e)
{
    static uint8_t r, g, b;

    lv_obj_t* slider = lv_event_get_target(e);
    rgb_mixer_t* user_data = lv_event_get_user_data(e);
    int32_t value = lv_slider_get_value(slider);
    lv_label_set_text_fmt(user_data->label, "%d", value);
    if (user_data->slider_type == SLIDER_R) {
        r = value;
    }else if(user_data->slider_type == SLIDER_G){
        g = value;
    }else if (user_data->slider_type == SLIDER_B) {
        b = value;
    }

    lv_obj_set_style_bg_color(rect,lv_color_make(r,g,b),LV_PART_MAIN);

}

void rgb_mixer_create_ui(void)
{
    static rgb_mixer_t r, g, b;

    r.slider_type = SLIDER_R;
    g.slider_type = SLIDER_G;
    b.slider_type = SLIDER_B;

    /*Create sliders*/
    lv_obj_t* slider_r = lv_slider_create(lv_scr_act());
    lv_obj_t* slider_g = lv_slider_create(lv_scr_act());
    lv_obj_t* slider_b = lv_slider_create(lv_scr_act());

    /*Set value range for sliders*/
    lv_slider_set_range(slider_r, 0, 255);
    lv_slider_set_range(slider_g, 0, 255);
    lv_slider_set_range(slider_b, 0, 255);

    /*Align sliders*/
    lv_obj_align(slider_r,LV_ALIGN_TOP_MID,0, 40);
    lv_obj_align_to(slider_g, slider_r, LV_ALIGN_TOP_MID,0,40);
    lv_obj_align_to(slider_b, slider_g, LV_ALIGN_TOP_MID, 0, 40);

    /* Create a base object to use it as rectangle */
    rect = lv_obj_create(lv_scr_act());
    lv_obj_set_size(rect, 300, 80);
    lv_obj_align_to(rect, slider_b, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_set_style_border_color(rect, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_border_width(rect, 5, LV_PART_MAIN);

    /*Setting background color to the various parts of the slider*/
    lv_obj_set_style_bg_color(slider_r,lv_palette_main(LV_PALETTE_RED),LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider_r, lv_palette_main(LV_PALETTE_RED), LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider_g, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider_g, lv_palette_main(LV_PALETTE_GREEN), LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider_b, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider_b, lv_palette_main(LV_PALETTE_BLUE), LV_PART_KNOB);

    lv_obj_t* heading = lv_label_create(lv_scr_act());
    lv_label_set_text(heading,"RGB Mixer");
    lv_obj_align(heading,LV_ALIGN_TOP_MID,0,10);

    r.label = lv_label_create(lv_scr_act());
    lv_label_set_text(r.label, "0");
    lv_obj_align_to(r.label, slider_r, LV_ALIGN_TOP_MID, 0, 0);

    g.label = lv_label_create(lv_scr_act());
    lv_label_set_text(g.label, "0");
    lv_obj_align_to(g.label, slider_g, LV_ALIGN_TOP_MID, 0, 0);

    b.label = lv_label_create(lv_scr_act());
    lv_label_set_text(b.label, "0");
    lv_obj_align_to(b.label, slider_b, LV_ALIGN_TOP_MID, 0, 0);


    lv_obj_add_event_cb(slider_r, slider_callback, LV_EVENT_VALUE_CHANGED, &r);
    lv_obj_add_event_cb(slider_g, slider_callback, LV_EVENT_VALUE_CHANGED, &g);
    lv_obj_add_event_cb(slider_b, slider_callback, LV_EVENT_VALUE_CHANGED, &b);
 
}
