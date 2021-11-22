#include <keyboard.h>
#include <lib.h>
#include <naiveConsole.h>
#include <inforeg.h>

#include <interrupts.h>

#define BUFFER_SIZE 64

//gonza
#define KEYS_SIZE 64

//chule y benja
// #define KEYS_SIZE 72

#define CAPSLOCK 58
#define SHIFTL 42
#define SHIFTR 54
#define SHIFTL_REL 170
#define SHIFTR_REL 180
#define REALEASED_KEY 200

// esc 1
// CAPS LOCK 58
// shift izq 42/170 shift der 54/180     (codigo cuando se apreta)/(codigo cuando se suelta)
// ctr 29
// alt 56
// flechas: arr72 abj 80, izq 75, der 77
// backspace = 14, tab 15, enter 28

//TECLADO GONZA
static const char lowerkeys[] = {
    0, '\e', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', /*'¿'*/ 0, 127, //14
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', /*'ñ'*/ 0, '+', '\n',    //28
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0, '{', 0, 0, '}',               //43
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', 0,                             //54
    0, 0, ' ',                                                                       //57
    0, 0, 0, 0, 0, 0, 0                                                              //64 lleno para poder usar BUFFER_SIZE en fill buffer
};

static const char upperKeys[] = {
    0, 0, '!', '"', '#', '$', '%', '&', '/', '(', ')', '=', '?', /*'¡'*/ 0, 127,  //14
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', /*'Ñ'*/ 0, '*', '\n', //28
    0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 0, '[', 0, 0, ']',            //43
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', ';', ':', '_', 0,                          //54
    0, 0, ' ',                                                                    //57
    0, 0, 0, 0, 0, 0, 0                                                           //64 lleno para poder usar BUFFER_SIZE en fillbuffer
};

//TECLADO CHULE Y BENJA
// static const char lowerkeys[] = {
//     0,'esc','1','2','3', '4', '5', '6', 0,0,'7', '8', '9', '0', //16
//     '\t',0,0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',0, 0, 'o', 'p','[',']','\n',0, //35
//     'a','s',0,0,'d','f','g','h','j','k','l',';',0,0,'\'',0,0,0,'z', //54
//     'x','c','v','b','n','m',',','.','/', 0,0,0,0,0,' ' //71
//     };

// // 0, 0, '1', '2', '3', '4', '5', '6', 0,0,'7', '8', '9', '0', '\'', /*'¿'*/0, 127, //16
//     // '\t',0,0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',0, 0, 'o', 'p', /*'ñ'*/0, '+', '\n', //32
//     // 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0, '{', 0, 0, '}', //43
//     // 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', 0, //54
//     // 0, 0, ' ', //57
//     // 0 //64 lleno para poder usar BUFFER_SIZE en fill buffer

// static const char upperKeys[] = {
//     0,'esc','1','2','3', '4', '5', '6', 0,0,'7', '8', '9', '0', //16
//     '\t',0,0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',0, 0, 'O', 'P','{','}','\n',0, //35
//     'A','S',0,0,'D','F','G','H','J','K','L',':',0,0,'"',0,0,0,'Z', //54
//     'X','C','V','B','N','M','<','>','?', 0,0,0,0,0,' ' //71
// };

static const char *keys[] = {lowerkeys, upperKeys};

static int capsLock = 0;

static char buffer[BUFFER_SIZE] = {0};
int bufferIdx = 0;

void clearBuffer();

void keyboard_handler()
{
    fillBuffer();
}

void fillBuffer()
{
    int pressedKey = getKey();
    if (pressedKey == 53)
    {
        saveRegs();
    }
    //|| pressedKey==SHIFTL_REL || pressedKey==SHIFTR_REL
    else if (pressedKey == CAPSLOCK || pressedKey == SHIFTL || pressedKey == SHIFTR)
    {
        capsLock = (capsLock + 1) % 2; //si era 0 pasa a ser 1, si era 1 pasa a 0
    }
    else
    {
        if (bufferIdx < BUFFER_SIZE && pressedKey < BUFFER_SIZE && pressedKey > 0)
        {
            if (keys[capsLock][pressedKey] != 0)
            {
                buffer[bufferIdx++] = keys[capsLock][pressedKey];
            }
        }
    }
}

int bufferCount()
{
    return bufferIdx;
}

char *getBuffer()
{
    return buffer;
}

void clearBuffer()
{
    while (bufferIdx > 0)
    {
        buffer[bufferIdx--] = 0;
    }
}
