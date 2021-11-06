#ifndef INTERRUPS_H_
#define INTERRUPS_H_

#include <naiveConsole.h>

void keyboard_handler();
char pressedKey();

void fillBuffer();
void clearBuffer();
char * getBuffer();
int bufferCount();

#endif