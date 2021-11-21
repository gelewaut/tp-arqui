#ifndef _TIME_H_
#define _TIME_H_

#include <stdint.h>

void timer_handler();
int ticks_elapsed();
int seconds_elapsed();
void halt(uint32_t seconds);

// uint64_t getRTC(uint64_t code);

#endif
