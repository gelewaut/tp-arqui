#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include <stdint.h>

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax);

uint64_t sys_read(int fd, char *buf, uint64_t count);
uint64_t sys_write(int fd, const char *buf, uint64_t count);
uint64_t sys_writeAT(char *character, uint64_t bytes, int x, int y);
uint64_t getTime (uint64_t code);
// uint64_t return_rax();
// uint64_t return_rbx();
// uint64_t return_rcx();
// uint64_t return_rdx();
// uint64_t return_rbp();
// uint64_t return_rsp();
// uint64_t return_rdi();
// uint64_t return_rsi();
// uint64_t return_r8();
// uint64_t return_r9();
// uint64_t return_r10();
// uint64_t return_r11();
// uint64_t return_r12();
// uint64_t return_r13();
// uint64_t return_r14();
// uint64_t return_r15();
void _saveReg();
void infoReg();
void saveRsp (uint64_t rsp);
void saveIp (uint64_t rip);
void saveReg(int i, uint64_t reg);
void memDump(uint64_t * direction);

#endif