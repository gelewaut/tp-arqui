#ifndef LIB_H
#define LIB_H

#include <stdint.h>

void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);

uint8_t port_byte_in(uint8_t port);
void port_byte_out(uint8_t port, uint8_t data);


char *cpuVendor(char *result);

// NUESTRAS ACA ABAJO

int strlenght(const char * string);

int strcmp(const char * str1, const char * str2);

void scanf();

void printf();

void getChar();

void putChar();

//ESTA FUNCION VA O NO?
char getKey();

#endif