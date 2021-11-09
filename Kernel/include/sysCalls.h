#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include <stdint.h>

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax);

uint64_t sys_read(int fd, char *buf, uint64_t count);
uint64_t sys_write(int fd, const char *buf, uint64_t count);
uint64_t sys_writeAT(char *character, uint64_t bytes, int x, int y);

void infoReg();
void memDump(uint64_t *direction);

#endif