#include <clock.h>
#include <syscalls.h>
#include <userlibc.h>

#define SCREEN_CLOCK_START_X 0
#define SCREEN_CLOCK_END_X 39
#define SCREEN_CLOCK_START_Y 15
#define SCREEN_CLOCK_END_Y 23

#define CLOCK_OFFSET_X 4
#define CLOCK_OFFSET_Y 5

static char *clockPrompt = "CLOCK hh/mm/ss: ";

/*
        CLOCK SCREEN:
       0    .   .   .   39
    15
    .
    .
    .
    23
*/
static char *hours, *minutes, *seconds;

void updateClock()
{
    // numToStr(hours, getHours(), 10);
    // numToStr(minutes, getMinutes(), 10);
    // numToStr(seconds, getSeconds(), 10);
    print_clock();
}

void print_clock()
{
    uint8_t i = 0;

    sys_writeAt(clockPrompt,string_lenght(clockPrompt), getClockX(i), getClockY());
    i=string_lenght(clockPrompt);
    sys_writeAt("          ",10,getClockX(i),getClockY());
    printHexAT(sys_clock(4), getClockX(i) ,getClockY());
    printCharAt(':', getClockX(i+2), getClockY());
    printHexAT(sys_clock(2), getClockX(i+3) ,getClockY());
    printCharAt(':', getClockX(i+5), getClockY());
    printHexAT(sys_clock(0), getClockX(i+6) ,getClockY());

    // printCharAt(hours[0],getClockX(i++), getClockY());
    // printCharAt(hours[1], getClockX(i++), getClockY());
    // printCharAt(minutes[0], getClockX(i++), getClockY());
    // printCharAt(minutes[1], getClockX(i++), getClockY());
    // printCharAt(seconds[0], getClockX(i++), getClockY());
    // printCharAt(seconds[1], getClockX(i++), getClockY());
}

uint8_t getClockX(uint8_t x)
{
    return SCREEN_CLOCK_START_X + CLOCK_OFFSET_X + x;
}

uint8_t getClockY()
{
    return SCREEN_CLOCK_START_Y + CLOCK_OFFSET_Y ;
}