#include <hangman.h>
#include <userlibc.h>
#include <sysCalls.h>

#define DICTIONARY_SIZE 6

const char * dictionary[DICTIONARY_SIZE] = {"chau", "hola", "gola","mesi","buen","malo",};

void processHangman(){
    // char * str = "Welcome to Hangman!";
    sys_writeAt("BIENVENIDO AL HANGMAN!",23,7,0);

    const char * word = "hola";
    int strlen = 4;

    int mask[strlen];
    for (int i=0; i < strlen; ++i) {
        mask[i] = 0;
    }

    int gameOver = 0;
    while (!gameOver)
    {
        sys_writeAt("La palabra es:",15,10,2);
        for (int i = 0; i < strlen; i++)
        {
            if (mask[i])
            {
                printCharAt(word[i], 24+i,2);
            }else{
                printCharAt('_', 24+ i,2);
            }
        }

        char guess;
        sys_writeAt("ELIJA UNA LETRA PARA INGRESAR",30,7,6);
        guess = getChar();

        int guessed = 0;
        for(int k=0; k < strlen; ++k) {
            if (word[k] == guess) {
	            mask[k] = 1;
                guessed = 1;
            }
        }

        if (!guessed)
        {
            sys_writeAt("LETRA INCORRECTA!",18,7,8);
        }else{
            sys_writeAt("                 ",18,7,8);
        }
        

        gameOver = 1;
        for(int m = 0; m < strlen; ++m) {
            if (!mask[m]) {
                gameOver = 0;
                break;
            }
        }
    }
        
        for (int i = 0; i < strlen; i++)
        {
            printCharAt(word[i], 24+i,2);
        }
    
    sys_writeAt("                             ",30,7,6);

    sys_writeAt("VICTORIA!",10,7, 10);
}