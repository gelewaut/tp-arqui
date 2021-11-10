#include <sysCalls.h>
#include <naiveConsole.h>

void fill_registers();
char * registers[16] = {"rax", "rbx", "rcx", "rdx", "rbp", "rdi", "rsi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",};

void infoReg() {
    fill_registers();
    ncPrintChar('\n');
    for (int i=0; i<15; i++) {
        ncPrint(registers[i]);
        ncPrintChar(' ');
    }
}