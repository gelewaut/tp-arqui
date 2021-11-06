#include <sysCalls.h>
#include <keyboard.h>

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