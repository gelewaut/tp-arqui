#include <fortune.h>
#include <stdint.h>
#include <userlibc.h>
#include <hangman.h>
#include <clock.h>
#include <chrono.h>
#include <sudoku.h>
#include <syscalls.h>

#define ESC '\e'
#define ROWS 25
#define COLS 80

uint8_t fortune_init()
{
    // Setup
    clear();
    print_welcome();
    print_limits();

    // Loop
    char c;
    while (1)
    {
        print_sudoku();
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
        print_chrono();
        print_clock();
    }

    // Shutdown
    clear();
    return 1;
}

void print_welcome()
{
    printf("Bienvenido a fortune \n");
    printf("Si desea salir, presione ESC \n");
    printf("Bienvenido a fortune \n");
    printf("Con las letras juegue a nuestro hangman \n");
    printf("Con los numeros juegue al sudoku \n");
    printf("Con las teclas . y , interactue con el cronometro \n");

    char c = 0;
    do
    {
        printf("Presione una tecla para comenzar \n");
    } while ((c = getChar()) == 0);

    clear();
}

/*
Dibuja los bordes
 col 40 hasta row 24: |
 row 15 y 24: -
*/
void print_limits()
{
    // cols
    for (int i = 0; i < ROWS; i++)
    {
        printCharAt('|', 40, i);
    }

    for (int i = 0; i < COLS; i++)
    {
        printCharAt('-', i, 15);
        printCharAt('-', i, 23);
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
    if ((c >= '1' && c <= '9') || (c == '\n'))
        return 1;
    return 0;
}

// uint8_t isChrono(uint8_t c)
// {
//     if (c == ',' || c == '.')
//     {
//         return 1;
//     }
//     return 0;
// }