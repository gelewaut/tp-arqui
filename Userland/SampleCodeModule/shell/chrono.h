#ifndef _CHRONO_H
#define _CHRONO_H

#include <stdint.h>

#define START_KEY '.'
#define PAUSE_KEY ','

#define CHRONO_SCREEN_START_X 15
#define CHRONO_SCREEN_END_X 23
#define CHRONO_SCREEN_START_Y 41
#define CHRONO_SCREEN_END_Y 80

#define CHRONO_OFFSET_X 3
#define CHRONO_OFFSET_Y 15

// ticks per second
#define TICK_FREQ 18

/*
    ARRANCA CON .
    PAUSA CON ,
    RESTART CON , ESTANDO YA PAUSADO
    RESUME CON . ESTANDO PAUSADO
*/

// resume
void resume();

// pausa
void pause();

// setea en 0.
void stop();

void print_chrono();

uint8_t isChrono(uint8_t key);
void processChrono(uint8_t key);
void updateChrono();
uint8_t hours_elapsed();
uint8_t minutes_elapsed();
uint8_t seconds_elapsed();
uint8_t decimals_elapsed();
uint64_t ticks_elapsed();
uint8_t getX();
uint8_t getY(uint8_t i);

#endif