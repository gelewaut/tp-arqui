/* sampleCodeModule.c */
// #define PROMPT "$>\t"
// #define MAX_BUFFER 1024

// static char * buffer[MAX_BUFFER];
// static int bufferIdx = 0;
// static char token;

// void shell_init();
// void clear_buffer();
// void interpret_line();
#include <syscalls.h>
#include <shell.h>
#include <userlibc.h>

int main()
{
	// clear();
	init_shell();
	// char c;
	// while (1) {
	// 	sys_read(0, &c, 1);
	// 	sys_write(0, &c, 1);
	// }

	return 0;
}

// void shell_init() {
//     while(1) {
//         while( (token = getchar()) != '\n') {
//             buffer[bufferIdx++] = token;
//         }
//         interpret_line(buffer);
//     }
// }

// void clear_buffer() {
//     for(int i = 0; i <= bufferIdx; i++) buffer[i] = 0;
//     bufferIdx = 0;
// }

// void interpret_line(const char * buffer) {
//     // TODO
//     clear_buffer();
// }
