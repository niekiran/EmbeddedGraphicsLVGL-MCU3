#include "ClockAlarmUI.h"
#include<stdio.h>

#if LV_CALENDAR_WEEK_STARTS_MONDAY
const  char* g_days[] = { "Monday", "Tuesday", "Wednseday", "Thursday", "Firday", "Saturday", "Sunday" };
#else
const  char* g_days[] = { "Sunday", "Monday", "Tuesday", "Wednseday", "Thursday", "Firday", "Saturday" };
#endif
const char* g_months[] = { "January" , "February", "March","April","May", "June", "July", "August","September",\
                          "October","November","December" };

////////////////////STATIC PRIVATE FUNCTIONS////////////////////////////////////
static uint32_t convert_24hformat_to_12h(uint32_t time24h);
static uint32_t convert_12hformat_to_24h(uint32_t time12h, time_format_t ampm);
static uint8_t  get_day_of_week(uint32_t year, uint32_t month, uint32_t day);
static bool is_settings_changed(const ClockAlarmUI* const me);
bool is_settings_time_changed(const ClockAlarmUI* const me);
bool is_settings_date_changed(const ClockAlarmUI* const me);
bool is_settings_alarm_changed(const ClockAlarmUI* const me);
static void integertime_to_string(uint32_t time_, char* const buf);
////////////////////////////////////////////////////////////////////////////////

/*
 * Description: converts an 'integer' time to 'String' time
 * param1 : time represented in terms of number of seconds
 * return : time as 'String' value in the format HH:MM:SS
 */
static void integertime_to_string(uint32_t time_, char* const buf) {
    uint8_t h, m, s;
    //char buf[10]; //00:00:00+null
    h = (uint8_t)GET_HOUR(time_); /* Extract how many hours the 'time_' represent */
    m = (uint8_t)GET_MIN(time_);  /* Extract how many minutes the 'time_' represent */
    s = (uint8_t)GET_SEC(time_);     /* Extract how many seconds the 'time_' represent */
    sprintf(buf, "%02d:%02d:%02d", h, m, s);
}


void ClockAlarmUI_update_current_time(ClockAlarmUI* const me) {
    uint32_t time24h;
    uint32_t time_;
    char time_as_string[10];
    time24h = Clock_get_current_time(&me->clock_inst);
    time_ = (Clock_get_time_mode(&me->clock_inst) == MODE_24H) ? time24h : \
        convert_24hformat_to_12h(time24h);
    integertime_to_string(time_, time_as_string);
    Lvgl_display_clock(&me->lvgl_inst, time_as_string);
}


void ClockAlarmUI_update_current_date(ClockAlarmUI* const me) {
    date_t new_date;
    Clock_get_date(&me->clock_inst, &new_date);
    if (me->state == STATE_SETTING) {
        Lvgl_display_calendar_date(&me->lvgl_inst, new_date.date, new_date.month, new_date.year);
    }
    else if (me->state == STATE_TICKING) {
        Lvgl_display_day(&me->lvgl_inst, g_days[new_date.day]);
        Lvgl_display_month(&me->lvgl_inst, g_months[new_date.month - 1]);
        Lvgl_display_date(&me->lvgl_inst, new_date.date);
        Lvgl_display_year(&me->lvgl_inst, new_date.year);
    }
}

void ClockAlarmUI_process_event(ClockAlarmUI* const me, UI_event_t* event)
{
    event_t e = event->sig;


    if (e == E_SETTING) {
        lvgl_setting_page_data_t setting_page_data;
        memset(&setting_page_data, 0, sizeof(lvgl_setting_page_data_t));

        me->usr_setting.time_now = convert_24hformat_to_12h(me->clock_inst.time_now);
        me->usr_setting.alarm_time = convert_24hformat_to_12h(me->clock_inst.alarm_time);
        me->usr_setting.time_format = Clock_get_am_or_pm(me->clock_inst.time_now);
        me->usr_setting.alarm_time_format = Clock_get_am_or_pm(me->clock_inst.alarm_time);

        me->setting_save.time_now = me->usr_setting.time_now;
        me->setting_save.alarm_time = me->usr_setting.alarm_time;
        me->setting_save.time_format = me->usr_setting.time_format;
        me->setting_save.alarm_time_format = me->usr_setting.alarm_time_format;

        uint32_t tmp = me->usr_setting.time_now;
        setting_page_data.clock_hour = GET_HOUR(tmp);
        setting_page_data.clock_min = GET_MIN(tmp);
        setting_page_data.clock_sec = GET_SEC(tmp);
        setting_page_data.clock_format = Clock_get_am_or_pm(me->clock_inst.time_now);
        setting_page_data.clock_mode = me->clock_inst.time_mode;

        tmp = me->usr_setting.alarm_time;
        setting_page_data.alarm_hour = GET_HOUR(tmp);
        setting_page_data.alarm_min = GET_MIN(tmp);
        setting_page_data.alarm_sec = GET_SEC(tmp);
        setting_page_data.alarm_format = Clock_get_am_or_pm(me->clock_inst.alarm_time);
        setting_page_data.alarm_status = me->clock_inst.alarm_status;


        date_t date_now;
        Clock_get_date(&me->clock_inst, &date_now);
        memcpy(&me->usr_setting.date_now, &date_now, sizeof(date_t));
        memcpy(&me->setting_save.date_now, &date_now, sizeof(date_t));

        setting_page_data.day = date_now.day;
        setting_page_data.date = date_now.date;
        setting_page_data.month = date_now.month;
        setting_page_data.year = date_now.year;


        Lvgl_screen_cleanup(&me->lvgl_inst);
        me->state = STATE_SETTING;
        Lvgl_create_setting_page(&me->lvgl_inst, &setting_page_data);
        ClockAlarmUI_update_current_time(me);
        ClockAlarmUI_update_current_date(me);
    }
    else if (e == E_ROOT_BACK) {
        if (is_settings_changed(me)) {
            //something is changed
            static const char* options[] = { "Yes","No","" };
            Lvgl_create_message_box(&me->lvgl_inst, "Settings", "Do you want to save changes?", options, false);
        }
        else {
            //nothing changed
            me->state = STATE_TICKING;
            Lvgl_screen_cleanup(&me->lvgl_inst);
            Lvgl_create_main_page(&me->lvgl_inst);
            Lvgl_main_page_set_style(&me->lvgl_inst);
            ClockAlarmUI_update_current_time(me);
            ClockAlarmUI_update_current_date(me);
        }

    }
    else if (e == E_SETTING_SAVE_YES_NO) {
        UI_generic_event_t* e = (UI_generic_event_t*)event;
        uint32_t time_format = 0;
        uint32_t new_time = 0;
        if (e->param == USER_SELECT_YES) {
            if (is_settings_date_changed(me)) {
                Clock_set_date(&me->clock_inst, &me->usr_setting.date_now);
            }
            else if (is_settings_time_changed(me)) {
                time_format = me->usr_setting.time_format;
                new_time = convert_12hformat_to_24h(me->usr_setting.time_now, time_format);
                Clock_set_current_time(&me->clock_inst, new_time);
            }
            else if (is_settings_alarm_changed(me)) {
                time_format = me->usr_setting.alarm_time_format;
                new_time = convert_12hformat_to_24h(me->usr_setting.alarm_time, time_format);
                Clock_set_alarm_time(&me->clock_inst, new_time);
            }
        }
        else {
            //discard
            ;
        }
        UI_STATE_CHANGE(STATE_TICKING);
        Lvgl_screen_cleanup(&me->lvgl_inst);
        Lvgl_create_main_page(&me->lvgl_inst);
        Lvgl_main_page_set_style(&me->lvgl_inst);
        ClockAlarmUI_update_current_time(me);
        ClockAlarmUI_update_current_date(me);
    }
    else if (e == E_SETTING_CLOCK_HOUR) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint32_t hour = e->param;
        me->usr_setting.time_now -= GET_HOUR(me->usr_setting.time_now) * 3600UL;
        me->usr_setting.time_now += hour * 3600UL;
    }
    else if (e == E_SETTING_CLOCK_MIN) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint32_t min = e->param;
        me->usr_setting.time_now -= GET_MIN(me->usr_setting.time_now) * 60UL;
        me->usr_setting.time_now += min * 60UL;
    }
    else if (e == E_SETTING_CLOCK_SEC) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint32_t sec = e->param;
        me->usr_setting.time_now -= GET_SEC(me->usr_setting.time_now);
        me->usr_setting.time_now += sec;
    }
    else if (E_SETTING_CLOCK_FORMAT == e) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint8_t id = e->param;
        if (id == 0) {
            me->usr_setting.time_format = FORMAT_AM;
        }
        else if (id == 1) {
            me->usr_setting.time_format = FORMAT_PM;
        }
    }
    else if (E_SETTING_CLOCK_MODE == e) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        me->clock_inst.time_mode = e->param;
    }
    else if (e == E_SETTING_ALARM_HOUR) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint32_t hour = e->param;
        me->usr_setting.alarm_time -= GET_HOUR(me->usr_setting.alarm_time) * 3600UL;
        me->usr_setting.alarm_time += hour * 3600UL;
    }
    else if (e == E_SETTING_ALARM_MIN) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint32_t min = e->param;
        me->usr_setting.alarm_time -= GET_MIN(me->usr_setting.alarm_time) * 60UL;
        me->usr_setting.alarm_time += min * 60UL;
    }
    else if (E_SETTING_ALARM_FORMAT == e) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        uint8_t id = e->param;
        if (id == 0) {
            me->usr_setting.alarm_time_format = FORMAT_AM;
        }
        else if (id == 1) {
            me->usr_setting.alarm_time_format = FORMAT_PM;
        }
    }
    else if (E_SETTING_DATE_CHANGE == e) {
        UI_date_change_event_t* e = (UI_date_change_event_t*)event;
        me->usr_setting.date_now.day = get_day_of_week(e->year, e->month, e->date);
        me->usr_setting.date_now.month = e->month;
        me->usr_setting.date_now.year = e->year;
        me->usr_setting.date_now.date = e->date;
    }
    else if (E_DATE_SAVE == e) {
        //save the date
        memcpy(&me->setting_save.date_now, &me->usr_setting.date_now, sizeof(date_t));
        Clock_set_date(&me->clock_inst, &me->usr_setting.date_now);
        ClockAlarmUI_update_current_date(me);
    }
    else if (E_CLOCK_SAVE == e) {
        me->setting_save.time_now = me->usr_setting.time_now;
        me->setting_save.time_format = me->usr_setting.time_format;
        uint32_t time_format = me->usr_setting.time_format;
        uint32_t new_time = convert_12hformat_to_24h(me->usr_setting.time_now, time_format);
        Clock_set_current_time(&me->clock_inst, new_time);
    }
    else if (E_ALARM_SAVE == e) {
        me->setting_save.alarm_time = me->usr_setting.alarm_time;
        me->setting_save.alarm_time_format = me->usr_setting.alarm_time_format;
        uint32_t time_format = me->usr_setting.alarm_time_format;
        uint32_t new_time = convert_12hformat_to_24h(me->usr_setting.alarm_time, time_format);
        Clock_set_alarm_time(&me->clock_inst, new_time);
    }
    else if (E_ALARM_ON_OFF == e) {
        UI_time_change_event_t* e = (UI_time_change_event_t*)event;
        me->clock_inst.alarm_status = e->param;
    }
    else if (E_ALARM_NOTIF_ON == e) {
        me->history = me->state;
        UI_STATE_CHANGE(STATE_ALARM);
       
        lvgl_alarm_page_data_t alarm_page_data;
        uint32_t tmp = me->usr_setting.time_now;
        alarm_page_data.clock_hour = GET_HOUR(tmp);
        alarm_page_data.clock_min = GET_MIN(tmp);
        alarm_page_data.clock_sec = GET_SEC(tmp);

        date_t date_now;
        Clock_get_date(&me->clock_inst, &date_now);
        alarm_page_data.date = date_now.date;
        alarm_page_data.month = date_now.month;
        alarm_page_data.year = date_now.year;
        Lvgl_screen_cleanup(&me->lvgl_inst);
        Lvgl_create_alarm_notif_page(&me->lvgl_inst, &alarm_page_data);
    }
    else if (E_ALARM_NOTIF_CLOSE == e) {
        Lvgl_screen_cleanup(&me->lvgl_inst);
        if (me->history == STATE_TICKING) {
            UI_STATE_CHANGE(STATE_TICKING);
            Lvgl_screen_cleanup(&me->lvgl_inst);
            Lvgl_create_main_page(&me->lvgl_inst);
            Lvgl_main_page_set_style(&me->lvgl_inst);
            ClockAlarmUI_update_current_time(me);
            ClockAlarmUI_update_current_date(me);
        }
        else if (me->history == STATE_SETTING) {
           
            uint32_t tmp;
            lvgl_setting_page_data_t setting_page_data;

            tmp = me->usr_setting.time_now;
            setting_page_data.clock_hour = GET_HOUR(tmp);
            setting_page_data.clock_min = GET_MIN(tmp);
            setting_page_data.clock_sec = GET_SEC(tmp);
            setting_page_data.clock_format = me->usr_setting.time_format;
            setting_page_data.clock_mode = me->clock_inst.time_mode;

            tmp = me->usr_setting.alarm_time;
            setting_page_data.alarm_hour = GET_HOUR(tmp);
            setting_page_data.alarm_min = GET_MIN(tmp);
            setting_page_data.alarm_sec = GET_SEC(tmp);
            setting_page_data.alarm_format = me->usr_setting.alarm_time_format;


            setting_page_data.day = me->usr_setting.date_now.day;
            setting_page_data.date = me->usr_setting.date_now.date;
            setting_page_data.month = me->usr_setting.date_now.month;
            setting_page_data.year = me->usr_setting.date_now.year;

            setting_page_data.alarm_status = me->clock_inst.alarm_status;
            UI_STATE_CHANGE(STATE_SETTING);
            Lvgl_create_setting_page(&me->lvgl_inst, &setting_page_data);
            ClockAlarmUI_update_current_time(me);
            ClockAlarmUI_update_current_date(me);
        }
    }
}



void ClockAlarmUI_ctor(ClockAlarmUI* const me) {
    UI_STATE_CHANGE(STATE_TICKING);
    Clock_ctor(&me->clock_inst);
    Lvgl_ctor(&me->lvgl_inst);
    Lvgl_create_main_page(&me->lvgl_inst);
    Lvgl_main_page_set_style(&me->lvgl_inst);
    /*Update current time on the display*/
    ClockAlarmUI_update_current_time(me);
    /*Update current date on the display*/
    ClockAlarmUI_update_current_date(me);
}

static uint32_t convert_24hformat_to_12h(uint32_t time24h) {
    uint8_t hour;
    uint32_t time12h;
    hour = GET_HOUR(time24h);

    if (hour == 0)
        time12h = time24h + (12UL * 3600UL);
    else {
        if ((hour < 12UL) || (hour == 12UL))
            return time24h;
        else
            time12h = time24h - (12UL * 3600UL);
    }
    return time12h;
}


/*
 * Description: Converts given integer time in 12H format to integer time 24H format
 * param1 : Integer time in 12H format
 * param2 : time format of type time_format_t
 * return : Integer time in 24H format
 */
static uint32_t convert_12hformat_to_24h(uint32_t time12h, time_format_t ampm) {
    uint8_t hour;
    uint32_t time24h;
    hour = GET_HOUR(time12h);
    if (ampm == FORMAT_AM) {
        time24h = (hour == 12) ? (time12h - (12UL * 3600UL)) : time12h;
    }
    else {
        time24h = (hour == 12) ? time12h : (time12h + (12UL * 3600UL));
    }
    return time24h;
}

static uint8_t get_day_of_week(uint32_t year, uint32_t month, uint32_t day)
{
    uint32_t a = month < 3 ? 1 : 0;
    uint32_t b = year - a;

#if LV_CALENDAR_WEEK_STARTS_MONDAY
    uint32_t day_of_week = (day + (31 * (month - 2 + 12 * a) / 12) + b + (b / 4) - (b / 100) + (b / 400) - 1) % 7;
#else
    uint32_t day_of_week = (day + (31 * (month - 2 + 12 * a) / 12) + b + (b / 4) - (b / 100) + (b / 400)) % 7;
#endif

    return day_of_week;
}

bool is_settings_date_changed(const ClockAlarmUI* const me) {
    if ((me->setting_save.date_now.day != me->usr_setting.date_now.day) || \
        (me->setting_save.date_now.date != me->usr_setting.date_now.date) || \
        (me->setting_save.date_now.month != me->usr_setting.date_now.month) || \
        (me->setting_save.date_now.year != me->usr_setting.date_now.year)) {
        return true;
    }
    LV_LOG_USER("Date has not changed\n");
    return false;
}

bool is_settings_time_changed(const ClockAlarmUI* const me) {
    uint32_t time24 = convert_12hformat_to_24h(me->usr_setting.time_now, me->usr_setting.time_format);
    if (convert_12hformat_to_24h(me->setting_save.time_now, me->setting_save.time_format) != time24) {
        return true;
    }
    LV_LOG_USER("Time has not changed\n");
    return false;
}

bool is_settings_alarm_changed(const ClockAlarmUI* const me) {
    uint32_t time24 = convert_12hformat_to_24h(me->usr_setting.alarm_time, me->usr_setting.alarm_time_format);
    if (convert_12hformat_to_24h(me->setting_save.alarm_time, me->setting_save.alarm_time_format) != time24) {
        return true;
    }
    LV_LOG_USER("Alarm time has not changed\n");
    return false;
}


static bool is_settings_changed(const ClockAlarmUI* const me)
{
    if (is_settings_date_changed(me) == true) {
        return true;
    }
    else if (is_settings_time_changed(me)) {
        return true;
    }
    else if (is_settings_alarm_changed(me)) {
        return true;
    }
    else {
        return false;
    }
}
