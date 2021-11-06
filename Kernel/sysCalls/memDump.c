#include <sysCalls.h>
#include <naiveConsole.h>
#define BYTES_TO_PRINT 32

void memDump(uint64_t * direction) {
    ncNewline();
    for(int i=0; i<BYTES_TO_PRINT; i++) {
        ncPrintHex(direction[i]);
        ncPrintChar(' ');
    }
    ncNewline();
}