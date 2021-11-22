#include <chrono.h>
#include <userlibc.h>
#include <syscalls.h>

static uint64_t start;

static uint8_t active = 0;
static uint8_t paused = 0;




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
        if (paused)
        {
            resume();
        }else{
            start = sys_timerTick();
        }
        
    }
    else if (key == PAUSE_KEY)
    {
        if (active)
            pause();
        else
            stop();
    }
    updateChrono();
}

void updateChrono()
{
    print_chrono();
}

void print_chrono()
{
    char *hours, *minutes, *seconds, *decimals;
    uint64_t hlen, mlen, slen, dlen;
    // printDec(seconds_elapsed());
    // hlen = numToStr(hours, hours_elapsed(), 10);
    // mlen = numToStr(minutes, minutes_elapsed(), 10);
    // slen = numToStr(seconds, seconds_elapsed(), 10);
    // dlen = numToStr(decimals, decimals_elapsed(), 10);

    // printf(hours);


    uint8_t i = 0;
    sys_writeAt("               ",15,getX(i),getY());
    printDecAT(hours_elapsed(), getX(i) ,getY());
    printCharAt(':', getX(i+2), getY());
    printDecAT(minutes_elapsed(), getX(i+3) ,getY());
    printCharAt(':', getX(i+5), getY());
    printDecAT(seconds_elapsed(), getX(i+6) ,getY());
    printCharAt(':', getX(i+8), getY());
    printDecAT(decimals_elapsed(), getX(i+9) ,getY());


    // printCharAt(hours[0], getX(i++), getY());
    // printCharAt(hours[1], getX(i++), getY());
    // printCharAt(':', getX(i++), getY());
    // printCharAt(minutes[0], getX(i++), getY());
    // printCharAt(minutes[1], getX(i++), getY());
    // printCharAt(':', getX(i++), getY());
    // printCharAt(seconds[0], getX(i++), getY());
    // printCharAt(seconds[1], getX(i++), getY());
    // printCharAt(':', getX(i++), getY());
    // printCharAt(decimals[0], getX(i++), getY());
    // printCharAt(decimals[1], getX(i++), getY());
}

uint64_t hours_elapsed()
{
    return (minutes_elapsed() / 60);
}

uint64_t minutes_elapsed()
{
    return ((seconds_elapsed() / 60) % 60);
}

uint64_t seconds_elapsed()
{
    return ((ticks_elapsed() / TICK_FREQ) % 60);
}

uint64_t decimals_elapsed()
{
    return ((ticks_elapsed() / 2) % 10);
}

uint64_t ticks_elapsed()
{
    return (sys_timerTick() - start);
}

void resume()
{
    if (paused)
    {
        active = 1;
    }
}

void pause()
{
    active = 0;
    paused = 1;
}

void stop(){
    start = 0;
}

uint8_t getX(uint8_t i)
{
    return CHRONO_OFFSET_X + CHRONO_SCREEN_START_X + i;
}

uint8_t getY()
{
    return CHRONO_SCREEN_START_Y + CHRONO_OFFSET_Y ;
}