#include <keyboard.h>
#include <lib.h>
#define BUFFER_SIZE 64

static int idx;
static int capsLock = 0;

static char * buffer = { '0' };
int bufferIdx = 0;

void clearBuffer();

char keyboardHandler(){
    // HAY QUE DEFINIR _keyHandler()
    // idx = _keyHandler();

    

    return buffer[bufferIdx];
}

char * getBuffer(){
    char * auxBuffer;
    auxBuffer = buffer;

    clearBuffer();
    return auxBuffer;
}

void clearBuffer(){
    while (bufferIdx >= 0)
    {
        buffer[bufferIdx--] = '0';
    }
    
}
