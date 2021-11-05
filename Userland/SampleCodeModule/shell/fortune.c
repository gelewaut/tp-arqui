#include <fortune.h>
#include <stdint.h>
#include <time.h>

#include <hangman.h>
#include <sudoku.h>

#define ESC 0

void fortune_init()
{
    ncClear();
    print_welcome();
    print_limits();
    char c;
    while ((c = getChar()) != ESC)
    {
        if (isHangman(c))
        {
            processHangman(c);
        }
        else if (isSudoku(c))
        {
            processSudoku(c);
        }
        else if (isChrono(c))
        {
            // processChrono(c);
        }
        // updateFortune();
    }
}

void print_welcome()
{
    ncPrintln("Bienvenido a fortune");
    ncPrintln("Si desea salir, presione ESC");
    ncPrintln("Bienvenido a fortune");
    ncPrintln("Con las letras juegue a nuestro hangman");
    ncPrintln("Con los numeros juegue al sudoku");
    ncPrintln("Con las teclas 'BACKSPACE' y 'SHIFTR' interactue con el cronometro");
    halt(5);
}

uint8_t isHangman(uint8_t c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

uint8_t isSudoku(uint8_t c)
{
    if ((c >= '1' && c <= '9') || (c == '\n') || isArrow(c))
        return 1;
    return 0;
}
