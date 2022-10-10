
#include "clock.h"
#include "ClockAlarmUI.h"

void Clock_update_current_time(Clock * const me) {
    if(++me->time_now == MAX_TIME){
        me->time_now = 0;
        //send update date event to UI obj
    }
}

bool Clock_is_alarm(Clock* const me) {
    return (me->time_now == me->alarm_time);
}

uint32_t Clock_get_current_time(Clock * const me) {
    return me->time_now; //fix this
}

uint8_t Clock_get_time_mode(Clock * const me) {
    return me->time_mode;
}

void Clock_set_current_time(Clock * const me, uint32_t new_time) {
    me->time_now = new_time;//fix_this
}

void Clock_set_alarm_time(Clock* const me, uint32_t new_time) {
    me->alarm_time = new_time;
}

void Clock_set_date(Clock * const me, date_t *const  new_date) {
    me->date_now.day = new_date->day;
    me->date_now.date = new_date->date;
    me->date_now.month = new_date->month;
    me->date_now.year = new_date->year;
}

void Clock_get_date(Clock * const me, date_t *const pdate) {
    pdate->day = me->date_now.day;
    pdate->date = me->date_now.date;
    pdate->month = me->date_now.month;
    pdate->year = me->date_now.year;
}

uint8_t Clock_get_am_or_pm(uint32_t time24h)
{
    uint8_t ampm;
    uint8_t h = (uint8_t)GET_HOUR(time24h);
    if (h == 0U) {
        ampm = FORMAT_AM;
    }
    else if (h > 12U) {
        ampm = FORMAT_PM;
    }
    else if (h == 12U)
        ampm = FORMAT_PM;
    else
        ampm = FORMAT_AM;
    return ampm;
}

void Clock_ctor(Clock *const me) {
    me->time_now = INITIAL_CURR_TIME;
    me->time_mode = MODE_24H;
    me->alarm_time = INITIAL_ALARM_TIME;
    me->date_now.day = INITIAL_DAY;
    me->date_now.date = INITIAL_DATE;
    me->date_now.month = INITIAL_MONTH;
    me->date_now.year = INITIAL_YEAR;
    me->alarm_status = INITIAL_ALARM_STATUS;
}


