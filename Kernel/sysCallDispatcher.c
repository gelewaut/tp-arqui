#include <stdint.h>

typedef uint64_t (*SysCall) (uint64_t, uint64_t, uint64_t);

uint64_t sys_write(int fd, const char * buf, uint64_t count);
uint64_t sys_read(int fd, char * buf, uint64_t count);

// De la misma manera aca podrian estar info_reg y mem_dump


static SysCall sysCalls[10] = { (SysCall)&sys_read, (SysCall)&sys_write,};




uint64_t sys_write(int fd, const char * buf, uint64_t count) {
    
    return 1;
}

uint64_t sys_read(int fd, char * buf, uint64_t count) {

    return 1;
}

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) {
    SysCall sysCall = sysCalls[rax];
    if (sysCall != 0) {
        return sysCall(rdi, rsi, rdx);
    }
}