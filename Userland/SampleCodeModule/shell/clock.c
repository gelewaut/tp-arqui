#include <clock.h>
#include <syscalls.h>
#include <userlibc.h>

#define SCREEN_CLOCK_START_X 15
#define SCREEN_CLOCK_END_X 23
#define SCREEN_CLOCK_START_Y 0
#define SCREEN_CLOCK_END_Y 39

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
    numToStr(hours, getHours(), 10);
    numToStr(minutes, getMinutes(), 10);
    numToStr(seconds, getSeconds(), 10);
    print_clock();
}

void print_clock()
{
    uint8_t i = 0;

    sys_writeAt(clockPrompt,17, getClockX(), getClockY(i));
    i=17;
    printCharAt(hours[0],getClockX(), getClockY(i++));
    printCharAt(hours[1], getClockX(), getClockY(i++));
    printCharAt(':', getClockX(), getClockY(i++));
    printCharAt(minutes[0], getClockX(), getClockY(i++));
    printCharAt(minutes[1], getClockX(), getClockY(i++));
    printCharAt(':', getClockX(), getClockY(i++));
    printCharAt(seconds[0], getClockX(), getClockY(i++));
    printCharAt(seconds[1], getClockX(), getClockY(i++));
}

uint8_t getClockX()
{
    return SCREEN_CLOCK_START_X + CLOCK_OFFSET_X;
}

uint8_t getClockY(uint8_t y)
{
    return SCREEN_CLOCK_START_Y + CLOCK_OFFSET_Y + y;
}