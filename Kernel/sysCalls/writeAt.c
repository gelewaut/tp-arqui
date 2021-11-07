#include <sysCalls.h>
#include <naiveConsole.h>

uint64_t sys_writeAT(char * character, uint64_t bytes, int x, int y) {
    return PrintAt(character, bytes, x, y);
    //completar
    // return 1;
}