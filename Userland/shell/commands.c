#include <commands.h>
#include <userlibc.h>
#include <fortune.h>

#define MAX_COMMAND_LENGHT 16
#define MAX_ARGS 3
#define MAX_ARG_LENGHT 5
#define NUMBER_OF_COMMANDS 2

/* 
** Pensar si estaria mal un struct Command que tenga nombre
** del command, cant de args del command y args posibles del command
*/

// The index in this array indicates the COMMAND_CODE
static const char * valid_commands[NUMBER_OF_COMMANDS] = {"help", "fortune"};
static const int commands_arg[NUMBER_OF_COMMANDS] = {0, 0};

static char * command_buffer[MAX_COMMAND_LENGHT];

static char * args_buffer[MAX_ARGS][MAX_ARG_LENGHT];

int isCommand(const char * buffer) {
    for (int i = 0; i < MAX_COMMAND_LENGHT; i++) {
        if (string_compare(buffer, valid_commands[i]))
        return i;
    }
    return 0;
}

// La idea seria que dado el buffer de la shell, deje en command_buffer el command
// y en args_buffer, en cada pos, el arg correspondiente.
// estaria bueno que se sepa cada comando cuantos args lleva
// eso pense hacerlo con el array commands_arg
void parseCommand(const char * buffer) {

}

void runCommand(uint8_t command_code, const char ** args) {
    switch (command_code) {
        case 0:
            helpCommand();
        case 1:
            fortuneCommand();
    }
}


void helpCommand() {
    // printear ayuda. Algo asi
    ncPrintln("The available commands are:");
    for (int i = 0; i < NUMBER_OF_COMMANDS; i++) {
        ncPrintln(valid_commands[i]);
    }
}

void fortuneCommand() {
    fortune_init();
}

