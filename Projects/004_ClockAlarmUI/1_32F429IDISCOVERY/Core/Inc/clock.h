
#ifndef CLOCK_H
#define CLOCK_H
#include<stdint.h>
#include<stdbool.h>

typedef struct {
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint16_t year;
}date_t;

enum {
    ALARM_ON,
    ALARM_OFF
};

#define SUNDAY 0
#define JUNE  5
#define MAX_TIME  (864000UL)
#define INITIAL_CURR_TIME  ((10UL * 3600UL + 10UL * 60UL + 10UL))
#define INITIAL_ALARM_TIME  (8UL * 3600UL)
#define INITIAL_DAY SUNDAY
#define INITIAL_MONTH  JUNE
#define INITIAL_YEAR  2022ul
#define INITIAL_DATE  12
#define INITIAL_ALARM_STATUS ALARM_ON
#define BASE_YEAR 2000

typedef enum time_mode {
    MODE_24H,
    MODE_12H
}time_mode_t;

typedef enum time_format{
    FORMAT_24H,
    FORMAT_AM,
    FORMAT_PM
}time_format_t;

#ifdef __cplusplus
extern "C"{
#endif

typedef struct {
    uint32_t time_now;
    uint32_t alarm_time;
    uint8_t time_format;
    uint8_t alarm_time_format;
    uint8_t alarm_status;
    uint8_t time_mode;
    date_t date_now;
} Clock;

void Clock_update_current_time(Clock * const me);
bool Clock_is_alarm(Clock *const me);
uint32_t Clock_get_current_time(Clock * const me);
uint8_t Clock_get_time_mode(Clock * const me);
void Clock_set_current_time(Clock * const me, uint32_t new_time);
void Clock_set_alarm_time(Clock* const me, uint32_t new_time);
void Clock_set_date(Clock * const me, date_t *const  new_date);
void Clock_get_date(Clock * const me, date_t *const pdate);
uint8_t Clock_get_am_or_pm(uint32_t time24h);
void Clock_ctor(Clock *const me);
#ifdef __cplusplus
}
#endif



#endif
