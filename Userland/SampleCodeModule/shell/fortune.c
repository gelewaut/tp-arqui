#include <fortune.h>
#include <stdint.h>
#include <time.h>

#include <hangman.h>
#include <clock.h>
#include <sudoku.h>
#include <syscalls.h>

#define ESC 0

void fortune_init()
{
    // Setup
    ncClear();
    print_welcome();
    print_limits();

    // Loop
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
        processClock();
    }

    // Shutdown
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

/*
Dibuja los bordes
 col 40 hasta row 24: |
 row 15 y 24: -
*/
void print_limits()
{
    // cols
    for (int i = 0; i < MAX_ROWS - 1; i++)
    {
        sys_writeAt('|', i, 40);
    }

    for (int i = 0; i < MAX_COLS; i++)
    {
        sys_writeAt('-', 15, i);
        sys_writeAt('-', 24, i);
    }
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
