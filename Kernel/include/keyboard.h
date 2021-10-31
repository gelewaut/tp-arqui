#ifndef INTERRUPS_H_
#define INTERRUPS_H_

void keyboardHandler();
char pressedKey();

void fillBuffer();
void clearBuffer();
char * getBuffer();
int bufferCount();

#endif