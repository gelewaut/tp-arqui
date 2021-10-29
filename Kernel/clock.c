#include <clock.h>

/*
    Reg#	  Description

    00        RTC seconds
    01        RTC seconds alarm
    02        RTC minutes
    03        RTC minutes alarm
    04        RTC hours
    05        RTC hours alarm
    06        RTC day of week
    07        RTC day of month
    08        RTC month
    09        RTC year
    
*/

uint8_t getRTCHours() {
    return getRTC(4);
}

uint8_t getRTCMinutes() {
    return getRTC(2);
}

uint8_t getRTCSeconds() {
    return getRTC(0);
}