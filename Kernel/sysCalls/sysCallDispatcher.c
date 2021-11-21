#include <sysCalls.h>
#include <lib.h>
#include <time.h>

typedef uint64_t (*SysCall) (uint64_t, uint64_t, uint64_t);

// De la misma manera aca podrian estar info_reg y mem_dump
extern uint64_t getRTC(uint64_t code);

static SysCall sysCalls[10] = { (SysCall)&sys_read, (SysCall)&sys_write, (SysCall)&getRTC};

uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) {
    SysCall sysCall = sysCalls[rax];
    if (sysCall != 0) {
        return sysCall(rdi, rsi, rdx);
    }
    return 0;
}

// uint64_t getTime (uint64_t code) {
//     port_byte_out(0x70,code);
//     return port_byte_in(0x71);
// }