#include <stdint.h>
#include <naiveConsole.h>
#include <keyboard.h>

typedef uint64_t (*SysCall) (uint64_t, uint64_t, uint64_t);

uint64_t sys_read(int fd, char * buf, uint64_t count);
uint64_t sys_write(int fd, const char * buf, uint64_t count);
uint64_t sys_writeAT(char character, int x, int y);

// De la misma manera aca podrian estar info_reg y mem_dump


static SysCall sysCalls[10] = { (SysCall)&sys_read, (SysCall)&sys_write, (SysCall)&sys_writeAT};



//fd 0 = STDOUT
uint64_t sys_write(int fd, const char * buf, uint64_t count) {
    int i;
    //falla si no hay nada en el buffer, o mal fd, o count negativo
    if (*buf==0 || fd!=0 || count<0)
        return -1;

    for (i=0; i<count; i++) {
        //hay que aclarar los casos para tab, enter y backspace (ascii 127) en ncPrintChar
        ncPrintChar(buf[i]);
    }
    return i;
}

//fd 0 = teclado
uint64_t sys_read(int fd, char * buf, uint64_t count) {
    //falla si mal fd, o count negativo
    if (fd!=0 || count<0)
        return -1;

    clearBuffer();
    while (bufferCount()<count) {
        fillBuffer();
    }

    char * bufferAux = getBuffer();
    int i;

    for (i=0; i<count; i++) {
        buf[i] = bufferAux[i];
    }
    clearBuffer();
    return i;
}

uint64_t sys_writeAT(char character, int x, int y) {
    PrintAt(character, x, y);
    return 1;
}


uint64_t sysCallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax) {
    SysCall sysCall = sysCalls[rax];
    if (sysCall != 0) {
        return sysCall(rdi, rsi, rdx);
    }
    return 0;
}