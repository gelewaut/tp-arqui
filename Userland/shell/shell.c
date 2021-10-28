#include "shell.h"
#define PROMPT "$>\t"
#define MAX_BUFFER 1024

static char * buffer[MAX_BUFFER];
static int bufferIdx = 0;
static char token;

void init_shell() {
    while(1) {
        while( (token = getchar()) != '\n') {
            buffer[bufferIdx++] = token;
        }
        interpret_line(buffer);
    }
}

void interpret_line(const char * buffer) {
    // TODO
    clear_buffer();
}

void clear_buffer() {
    for(int i = 0; i <= bufferIdx; i++) buffer[i] = 0;
    bufferIdx = 0;
}