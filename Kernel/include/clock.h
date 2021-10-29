#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <stdint.h>

uint8_t getRTC(uint8_t code);

uint8_t getRTCHours();
uint8_t getRTCMinutes();
uint8_t getRTCSeconds();

#endif