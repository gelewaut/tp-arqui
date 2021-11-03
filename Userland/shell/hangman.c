#include <hangman.h>
#include <userlibc.h>
#define DICTIONARY_SIZE 3

const char * dictionary[DICTIONARY_SIZE] = {"chau", "hola", "gola","mesi","buen","malo",};

void processHangman(){
    printf("Welcome to Hangman! \n");
    int number;
    do
    {
        printf("Please choose a number from 1 to 6: ");
        scanf("%d",&number);

    } while (number < 0 || number > 6);
    
    char * word = dictionary[number-1];
    int strlen = 4;

    int mask[strlen];
    for (int i=0; i < strlen; ++i) {
        mask[i] = 0;
    }

    int gameOver = 0;
    while (!gameOver)
    {
        printf("The word is:");
        for (int i = 0; i < strlen; i++)
        {
            if (mask[i])
            {
                printf("%c",word[i]);
            }else{
                printf("_");
            }
        }
        printf("\n");

        char guess;
        printf("Letter?");
        scanf("%c", &guess);

        for(int k=0; k < strlen; ++k) {
            if (word[k] == guess) {
	            mask[k] = 1;
            }
        }

        gameOver = 1;
        for(int m = 0; m < strlen; ++m) {
            if (!mask[m]) {
                gameOver = 0;
                break;
            }
        }
    }
    
    printf("Victory! The word is \"%s\".\n", word);
}