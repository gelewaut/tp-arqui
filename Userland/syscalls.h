#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include <stdint.h>

uint64_t sys_read(int fd, char * buf, uint64_t count);

uint64_t sys_write(int fd, const char * buf, uint64_t count);

uint64_t sys_clock(uint64_t code);

#endif