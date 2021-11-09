#include <shell.h>
#include <userlibc.h>
#include <stdint.h>
#include <syscalls.h>
#include <fortune.h>
#include <shell.h>

#define PROMPT "$>"
#define MAX_BUFFER 128
#define MAX_COMMAND_LENGHT 8
#define MAX_ARGS 0
#define MAX_ARG_LENGHT 0
#define NUMBER_OF_COMMANDS 6

#define BACKSPACE 127
#define ENTER '\n'

#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0

static char shell_buffer[MAX_BUFFER+1] = {0};
static int bufferIdx = 0;
static char command_buffer[MAX_COMMAND_LENGHT+1] = {0};
static char args[MAX_ARGS][MAX_ARG_LENGHT+1];

static char * valid_commands[NUMBER_OF_COMMANDS] = {
    "exit",
    "help",    // 0
    "fortune",  // 1
    "time",     // 2
    "inforeg",  // 3
    "printmem", // 4
};

// static uint8_t args_for_command[NUMBER_OF_COMMANDS] = {
//     0,
//     0,
//     0,
//     0,
//     0};

void init_shell()
{
    // setup
    clear();
    shell_welcome();

    //loop
    shell_loop();

    //shutdown
}

void shell_welcome()
{
    printf("WELCOME TO SHELL");
}

void shell_loop()
{
    uint8_t mustContinue = 1;

    do
    {
        putChar('\n');
        printf(PROMPT);
        shell_read_line();
        shell_parse_line();
        // printf(command_buffer);
        mustContinue = shell_execute();
        cleanup();

    } while (mustContinue);
}

void shell_read_line()
{
    uint8_t c;

    while ((c = getChar()) != ENTER)
    {
        if (c == BACKSPACE)
        {
            if (bufferIdx>0) {
            shell_buffer[--bufferIdx] = 0;
            putChar(c);
            }
        }
        else
        {
            shell_buffer[bufferIdx++] = c;
            putChar(c);
        }
    }
}

void shell_parse_line()
{
    uint8_t args_counter = 0;
    uint8_t buffer_idx = 0;
    uint8_t aux_idx = 0;

    uint8_t token;

    while (shell_buffer[buffer_idx] && args_counter <= MAX_ARGS)
    {
        token = shell_buffer[buffer_idx++];
        if (token == ' ')
        {
            args_counter++;
            aux_idx = 0;
            continue;
        }
        if (args_counter == 0)
        {
            command_buffer[aux_idx++] = token;
        }
        else
        {
            args[args_counter - 1][aux_idx++] = token;
        }
    }
}

uint8_t shell_execute()
{
    int8_t cmd = isCommand(), result = 1;
    if (cmd > 0)
    {
        result = runCommand(cmd);
    }else if (cmd == 0)
    {
        return 0;
    } else{
        printf("\nUnknown command");
    }
    cleanup();
    return result;
}

int8_t isCommand()
{
    for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
    {
        if (string_compare(command_buffer, valid_commands[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int8_t runCommand(int8_t cmd)
{
    switch (cmd)
    {
    // En cada caso puedo definir si le paso args si es necesario
    // y cuantos les paso
    case 1:
    {
        return helpCommand();
        break;
    }
    case 2:
    {
        return fortuneCommand();
        break;
    }
    case 3:
    {
        return timeCommand();
        break;
    }
    case 4:
    {
        return inforegCommand();
        break;
    }
    case 5:
    {
        return printmemCommand();
        break;
    }
    }
    return -1;
}

uint8_t helpCommand()
{
    printf("\nThese are the available commands");
    for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
    {
        putChar('\n');
        printf(valid_commands[i]);
    }
    putChar('\n');
    return EXIT_SUCCESS;
}

uint8_t timeCommand()
{
    uint8_t hours, minutes, seconds;

    hours = getHours();
    minutes = getMinutes();
    seconds = getSeconds();

    printf("TIME: %d:%d:%d\n", hours, minutes, seconds);

    return EXIT_SUCCESS;
}

uint8_t fortuneCommand()
{
    fortune_init();
    return EXIT_SUCCESS;
}

uint8_t inforegCommand(){
    putChar('\n');
    sys_infoReg();
    putChar('\n');
    return EXIT_SUCCESS;
}

uint8_t printmemCommand(){
    sys_printMem(0x000000);
    return EXIT_SUCCESS;
}

void cleanup()
{
    clear_buffer();
    clear_command_buffer();
    clear_args();
}

void clear_buffer()
{
    for (int i = 0; i <= bufferIdx; i++)
        shell_buffer[i] = 0;
    bufferIdx = 0;
}

void clear_command_buffer()
{
    for (int i = 0; i < MAX_COMMAND_LENGHT; i++)
        command_buffer[i] = 0;
}

void clear_args()
{
    for (int i = 0; i < MAX_ARGS; i++)
    {
        for (int j = 0; j < MAX_ARG_LENGHT; j++)
        {
            args[i][j] = 0;
        }
    }
}