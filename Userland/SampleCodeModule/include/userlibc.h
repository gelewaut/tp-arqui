#ifndef _USERLIBC_H
#define _USERLIBC_H

#include <stdint.h>

uint64_t numToStr(char * buf, unsigned long int num, int base);
int strToNum(char *str);
int string_compare(const char *s1, const char *s2);
void printf(char *string, ...);
int scanf(char *string, ...);
char getChar();
void putChar(char c);
void printDec(int num);
void printHex(int num);
void cleanBuffer();
uint8_t getHours();
uint8_t getMinutes();
uint8_t getSeconds();
uint64_t getTicks();

#endif