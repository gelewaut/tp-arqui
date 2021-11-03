#ifndef SYS_CALL_DISPATCHER_H_
#define SYS_CALL_DISPATCHER_H_
#include <stdint.h>

uint64_t sys_write(int fd, const char * buf, uint64_t count);

uint64_t sys_read(int fd, char * buf, uint64_t count);

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) ;

#endif