#include <hangman.h>
#include <userlibc.h>
#include <sysCalls.h>

#define DICTIONARY_SIZE 6

static int mask[4] = {0};
static const char *word = "hola";
static int strlen = 4;
static gameOver = 0;

void processHangman(char c)
{
    // char * str = "Welcome to Hangman!";
    sys_writeAt("BIENVENIDO AL HANGMAN!", 23, 7, 0);

    if (!gameOver)
    {
        sys_writeAt("La palabra es:", 15, 10, 2);
        for (int i = 0; i < strlen; i++)
        {
            if (c == word[i] || mask[i])
            {
                printCharAt(word[i], 24 + i, 2);
                mask[i] = 1;
            }
            else
            {
                printCharAt('_', 24 + i, 2);
            }
        }

        gameOver = 1;
        for (int m = 0; m < strlen; m++)
        {
            if (!mask[m])
            {
                gameOver = 0;
                break;
            }
        }
    }

    if (gameOver)
    {
        sys_writeAt("VICTORIA!", 10, 7, 10);
    }
}