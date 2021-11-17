#include <sysCalls.h>
#include <naiveConsole.h>

void fill_registers();
char * registers[16] = {"rax", "rbx", "rcx", "rdx", "rbp","rsp", "rdi", "rsi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"};
static uint64_t registers_values[16] = {0}; 

void infoReg() {
    // fill_registers();
    ncPrintChar('\n');
    for (int i=0; i<16; i++) {
        ncPrint(registers[i]);
        ncPrintChar(' ');
        ncPrintHex(registers_values[i]);
        ncPrintChar('\n');
    }
}

void saveReg(){
    int i = 0;

    registers_values[i++] = return_rax();
    registers_values[i++] = return_rbx();
    registers_values[i++] = return_rcx();
    registers_values[i++] = return_rdx();
    registers_values[i++] = return_rbp();
    registers_values[i++] = return_rsp();
    registers_values[i++] = return_rdi();
    registers_values[i++] = return_rsi();
    registers_values[i++] = return_r8();
    registers_values[i++] = return_r9();
    registers_values[i++] = return_r10();
    registers_values[i++] = return_r11();
    registers_values[i++] = return_r12();
    registers_values[i++] = return_r13();
    registers_values[i++] = return_r14();
    registers_values[i++] = return_r15();
}