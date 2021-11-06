#include <clock.h>
#include <syscalls.h>
#include <userlibc.h>

#define SCREEN_CLOCK_START_X 15
#define SCREEN_CLOCK_END_X 23
#define SCREEN_CLOCK_START_Y 0
#define SCREEN_CLOCK_END_Y 39

#define CLOCK_OFFSET_X 4
#define CLOCK_OFFSET_Y 5

const static uint8_t *clockPrompt = "CLOCK hh/mm/ss: ";

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
    hours = numToStr(getHours(), 10);
    minutes = numToStr(getMinutes(), 10);
    seconds = numToStr(getSeconds(), 10);
    print_clock();
}

void print_clock()
{
    uint8_t i = 0;

    for (i; clockPrompt[i]; i++)
    {
        sys_writeAt(clockPrompt[i],1, getX(), getY(i));
    }
    sys_writeAt(hours[0],1, getX(), getY(i++));
    sys_writeAt(hours[1],1, getX(), getY(i++));
    sys_writeAt(':',1, getX(), getY(i++));
    sys_writeAt(minutes[0],1, getX(), getY(i++));
    sys_writeAt(minutes[1],1, getX(), getY(i++));
    sys_writeAt(':', getX(),1, getY(i++));
    sys_writeAt(seconds[0],1, getX(), getY(i++));
    sys_writeAt(seconds[1],1, getX(), getY(i++));
}

uint8_t getX()
{
    return SCREEN_CLOCK_START_X + CLOCK_OFFSET_X;
}

uint8_t getY(uint8_t y)
{
    return SCREEN_CLOCK_START_Y + CLOCK_OFFSET_Y + y;
}