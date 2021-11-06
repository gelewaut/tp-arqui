#include <fortune.h>
#include <stdint.h>
#include <userlibc.h>
#include <hangman.h>
#include <clock.h>
#include <chrono.h>
#include <sudoku.h>
#include <syscalls.h>

#define ESC 0

void fortune_init()
{
    // Setup
    clear();
    print_welcome();
    print_limits();

    // Loop
    char c;
    while (1)
    {
        c = getChar();
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
            processChrono(c);
        }
        else if (c == ESC)
        {
            break;
        }
        updateChrono();
        updateClock();
    }

    // Shutdown
    return 1;
}

void print_welcome()
{
    printf("Bienvenido a fortune \n");
    printf("Si desea salir, presione ESC \n");
    printf("Bienvenido a fortune \n");
    printf("Con las letras juegue a nuestro hangman \n");
    printf("Con los numeros juegue al sudoku \n");
    printf("Con las teclas 'BACKSPACE' y 'SHIFTR' interactue con el cronometro \n");
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
        sys_writeAt('|',1, i, 40);
    }

    for (int i = 0; i < MAX_COLS; i++)
    {
        sys_writeAt('-',1, 15, i);
        sys_writeAt('-',1, 24, i);
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

uint8_t isChrono(uint8_t c)
{
    if (c == ',' || c == '.')
    {
        return 1;
    }
    return 0;
}