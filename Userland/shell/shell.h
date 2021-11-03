#ifndef _SHELL_H_
#define _SHELL_H_

void init_shell();
void shell_welcome();
void shell_loop();
void shell_read_line();
void shell_parse_line();
uint8_t shell_execute();
int8_t isCommand(const char * command);
uint8_t runCommand(uint8_t cmd);
uint8_t helpCommand();
uint8_t timeCommand();
void cleanup();
void clear_buffer();
void clear_command_buffer();
void clear_args();

#endif