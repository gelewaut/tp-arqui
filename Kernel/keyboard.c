#include <keyboard.h>
#include <lib.h>
#define BUFFER_SIZE 64

#define CAPSLOCK 58
#define SHIFTL 42
#define SHIFTR 54
#define SHIFTL_REL 170
#define SHIFTR_REL 180

// esc 1 
// CAPS LOCK 58
// shift izq 42/170 shift der 54/180     (codigo cuando se apreta)/(codigo cuando se suelta)
// ctr 29
// alt 56
// flechas: arr72 abj 80, izq 75, der 77
// backspace = 14, tab 15, enter 28

static const char lowerkeys[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', /*'¿'*/0, 127, //14
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', /*'ñ'*/0, '+', '\n', //28
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0, '{', 0, 0, '}', //43
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', 0, //54
    0, 0, ' ', //57
    0,0,0,0,0,0,0 //64 lleno para poder usar BUFFER_SIZE en fill buffer
};
static const char upperKeys[] = {
    0, 0, '!', '"', '#', '$', '%', '&', '/', '(', ')', '=', '?', /*'¡'*/0, 127, //14
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', /*'Ñ'*/0, '*', '\n', //28
    0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 0, '[', 0, 0, ']', //43
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', ';', ':', '_', 0, //54
    0, 0, ' ', //57
    0,0,0,0,0,0,0 //64 lleno para poder usar BUFFER_SIZE en fillbuffer
};
static const char * keys [] = {lowerkeys, upperKeys};

static int capsLock = 0;

static char buffer[BUFFER_SIZE] = {0};
int bufferIdx = 0;

void clearBuffer();

void keyboard_handler(){
    // HAY QUE DEFINIR _keyHandler()
    // idx = _keyHandler();

    

    // return buffer[bufferIdx-1];
}

void fillBuffer() {
    int i = getKey(); //falta definir getkey
    if (i==CAPSLOCK || i==SHIFTL || i==SHIFTR || i==SHIFTL_REL || i==SHIFTR_REL) {
        capsLock = (capsLock+1)%2; //si era 0 pasa a ser 1, si era 1 pasa a 0
    }
    if (i<= BUFFER_SIZE) {
        if (keys[capsLock][i] != 0) {
            buffer[bufferIdx++] = keys[capsLock][i];
        }
    }
}

int bufferCount () {
    return bufferIdx;
}

char * getBuffer(){
    return buffer;
}

void clearBuffer(){
    while (bufferIdx > 0) {
        buffer[bufferIdx--] = 0;
    }    
}
