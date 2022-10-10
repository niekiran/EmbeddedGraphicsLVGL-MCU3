
#ifndef CLOCK_ALARM_UI_H
#define CLOCK_ALARM_UI_H

#include "glvgl.h"
#include "clock.h"

#define GET_HOUR(seconds)     ((uint8_t)(seconds/3600UL))
#define GET_MIN(seconds)      ((uint8_t)((seconds/60UL)%60UL))
#define GET_SEC(seconds)      ((uint8_t)(seconds % 60UL))
#define DIGIT1(d)             ((uint8_t)(d/10U))
#define DIGIT2(d)             ((uint8_t)(d%10U))

typedef enum  {
    STATE_TICKING,
    STATE_SETTING,
    STATE_ALARM
}UI_state_t;


/*Various signals(events) generated in the application*/
typedef enum {
    E_SETTING, /*signal generated when user clicks the 'Settings' option from the drop down list*/
    E_ROOT_BACK,
    E_SETTING_CLOCK_HOUR,
    E_SETTING_CLOCK_MIN,
    E_SETTING_CLOCK_SEC,
    E_SETTING_CLOCK_FORMAT,
    E_SETTING_CLOCK_MODE,
    E_SETTING_DATE_CHANGE,
    E_SETTING_ALARM_HOUR,
    E_SETTING_ALARM_MIN, /*signal generated when user rolls the roller to set a new value on the alarm min roller*/
    E_SETTING_ALARM_FORMAT, 
    E_ALARM_ON_OFF,
    E_SETTING_SAVE_YES_NO,
    E_DATE_SAVE,
    E_CLOCK_SAVE,
    E_ALARM_SAVE,
    E_ALARM_NOTIF_ON,
    E_ALARM_NOTIF_CLOSE,
    E_NONE
}event_t;

enum { USER_SELECT_YES , USER_SELECT_NO};

#define  UI_STATE_CHANGE(s)   (me->state = s)

typedef struct
{
    event_t sig;
}UI_event_t;

typedef struct
{
    UI_event_t super;
    uint32_t param;
}UI_time_change_event_t;

typedef struct
{
    UI_event_t super;
    uint8_t param;
}UI_generic_event_t;

typedef struct
{
    UI_event_t super;
    uint32_t date;
    uint32_t day;
    uint32_t month;
    uint32_t year;
}UI_date_change_event_t;


/*Main application structure*/
typedef struct {
    Clock clock_inst;
    Lvgl lvgl_inst;
    UI_state_t state;
    UI_state_t history;
    Clock usr_setting;
    Clock setting_save;
} ClockAlarmUI;


#ifdef __cplusplus
extern "C"{
#endif

extern  ClockAlarmUI ClockAlarmUI_inst;
void ClockAlarmUI_ctor(ClockAlarmUI *const me);
void ClockAlarmUI_update_current_time(ClockAlarmUI* const me);
void ClockAlarmUI_update_current_date(ClockAlarmUI* const me);
void ClockAlarmUI_process_event(ClockAlarmUI* const me, UI_event_t* event);
#ifdef __cplusplus
}
#endif

#endif
