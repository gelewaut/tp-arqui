#include <sysCalls.h>
#include <keyboard.h>

#define BUFF_SIZE 256
#define STDIN 0

static char buffer[BUFF_SIZE] = {0};
static int rdIdx = 0; //Posicion de escritura
static int activeSize = 0; //Elementos legibles en el buffer

int dumpChar();
int dumpBuffer(char* destination, int size);

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


//, uint64_t r8, uint64_t r9 parametros que sobraban
uint64_t sys_readNoStop(uint64_t fd, uint64_t buffer, uint64_t length)
{
    if (fd != STDIN) {
        return -1;
    }
    char* buff = (char *) buffer;
    return dumpBuffer(buff,length);

}

int dumpBuffer(char* destination, int size)
{
    //Solo lee los elementos pertinentes
    if (size<=0 || activeSize<=0)
        return -1;

    int idx=0;
    while (idx<size-1 && activeSize){
        destination[idx] = dumpChar();
        idx++;
    }
    destination[idx]=0;
    return idx;
}

int dumpChar()
{
    if (activeSize <= 0) 
        return -1;

    int c = buffer[rdIdx];
    rdIdx = (rdIdx + 1) % BUFF_SIZE;
    activeSize--;
    return c;
}