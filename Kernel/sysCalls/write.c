#include <sysCalls.h>
#include <keyboard.h>

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