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
    printCharAt(hours[0], getX(), getY(i++));
    printCharAt(hours[1], getX(), getY(i++));
    printCharAt(':', getX(), getY(i++));
    printCharAt(minutes[0], getX(), getY(i++));
    printCharAt(minutes[1], getX(), getY(i++));
    printCharAt(':', getX(), getY(i++));
    printCharAt(seconds[0], getX(), getY(i++));
    printCharAt(seconds[1], getX(), getY(i++));
    printCharAt(':', getX(), getY(i++));
    printCharAt(decimals[0], getX(), getY(i++));
    printCharAt(decimals[1], getX(), getY(i++));
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
    return sys_timerTick() - start;
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