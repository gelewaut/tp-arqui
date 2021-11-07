#include <chrono.h>
#include <userlibc.h>
#include <syscalls.h>

static uint64_t start;

static uint8_t active = 0;
static uint8_t paused = 0;

static char *hours, *minutes, *seconds, *decimals;
static uint64_t hlen, mlen, slen, dlen;

uint8_t isChrono(uint8_t key)
{
    if (key == START_KEY || key == PAUSE_KEY)
        return 1;
    return 0;
}

void processChrono(uint8_t key)
{
    if (key == START_KEY)
    {
        if (!active)
            resume();
    }
    else if (key == PAUSE_KEY)
    {
        if (active)
            pause();
        else
            stop();
    }
}

void updateChrono()
{
    print_chrono();
}

void print_chrono()
{
    hlen = numToStr(hours, hours_elapsed(), 10);
    mlen = numToStr(minutes, minutes_elapsed(), 10);
    slen = numToStr(seconds, seconds_elapsed(), 10);
    dlen = numToStr(decimals, decimals_elapsed(), 10);

    uint8_t i = 0;
    sys_writeAt(&hours[0], 1, getX(), getY(i++));
    sys_writeAt(&hours[1], 1, getX(), getY(i++));
    sys_writeAt(":", 1, getX(), getY(i++));
    sys_writeAt(&minutes[0], 1, getX(), getY(i++));
    sys_writeAt(&minutes[1], 1, getX(), getY(i++));
    sys_writeAt(":", 1, getX(), getY(i++));
    sys_writeAt(&seconds[0], 1, getX(), getY(i++));
    sys_writeAt(&seconds[1], 1, getX(), getY(i++));
    sys_writeAt(":", 1, getX(), getY(i++));
    sys_writeAt(&decimals[0], 1, getX(), getY(i++));
    sys_writeAt(&decimals[1], 1, getX(), getY(i++));
}

uint8_t hours_elapsed()
{
    return minutes_elapsed() / 60;
}

uint8_t minutes_elapsed()
{
    return (seconds_elapsed() / 60) % 60;
}

uint8_t seconds_elapsed()
{
    return (ticks_elapsed() / TICK_FREQ) % 60;
}

uint8_t decimals_elapsed()
{
    return (ticks_elapsed() / 2) % 10;
}

uint64_t ticks_elapsed()
{
    return getTicks() - start;
}

void resume()
{
    active = 1;
    if (paused)
    {
    }
}

void pause()
{
    active = 0;
    paused = 1;
}

void stop()
{
    start = 0;
}

uint8_t getX()
{
    return CHRONO_OFFSET_X + CHRONO_SCREEN_START_X;
}

uint8_t getY(uint8_t i)
{
    return CHRONO_SCREEN_START_Y + CHRONO_OFFSET_Y + i;
}