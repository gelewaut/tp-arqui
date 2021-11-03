#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdint.h>

int isCommand(const char * buffer);

void parseCommand(const char * buffer);

void runCommand(uint8_t command_code, const char ** args);

#endif