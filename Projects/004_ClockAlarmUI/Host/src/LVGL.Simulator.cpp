/*
 * PROJECT:   LVGL PC Simulator using Visual Studio
 * FILE:      LVGL.Simulator.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>
#include<sysinfoapi.h>
#include "resource.h"
#include "bsp.h"
#include <stdlib.h>   /* for exit() */

#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/win32drv/win32drv.h"

#include "ClockAlarmUI.h"
#include "glvgl.h"
#include "clock.h"

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

#include <stdio.h>

/*Main application object*/
ClockAlarmUI ClockAlarmUI_inst;

int main()
{

    static ULONGLONG millis_1,millis_2;
    UI_event_t event;
   

    lv_init();

    /*Here you can change the display resolution*/
    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        480,
        270,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return -1;
    }

    lv_win32_add_all_input_devices_to_group(NULL);

    /*Constructor of the ClockAlarmUI object*/
    ClockAlarmUI_ctor(&ClockAlarmUI_inst);


    millis_1 = GetTickCount64();
    millis_2 = GetTickCount64();
    while (!lv_win32_quit_signal)
    {
        if (GetTickCount64() - millis_1 > 5UL) {
            lv_task_handler();
            millis_1 = GetTickCount64();
        }

        if (GetTickCount64() - millis_2 >= 1000UL) {
            /*Update current time on the display*/
            Clock_update_current_time(&ClockAlarmUI_inst.clock_inst);
            /*Update current time on the display*/
            ClockAlarmUI_update_current_time(&ClockAlarmUI_inst);
            /*Check for alarm*/
            if (Clock_is_alarm(&ClockAlarmUI_inst.clock_inst) && ClockAlarmUI_inst.clock_inst.alarm_status == ALARM_ON) {
                event.sig = E_ALARM_NOTIF_ON;
                ClockAlarmUI_process_event(&ClockAlarmUI_inst, &event);
            }
            millis_2 = GetTickCount64();
        }
    }

    return 0;

}


