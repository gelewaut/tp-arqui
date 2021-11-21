#include <naiveConsole.h>
#include <sysCalls.h>

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 0

extern void print_ip();

void zero_division();
void invalid_OPCODE();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if (exception == OPCODE_EXCEPTION_ID)
		invalid_OPCODE();
}

void zero_division() {
	ncPrintChar('\n');
	ncPrintFormat("Division By Zero ",RED,BLACK);
	ncPrint("Instruction Pointer: ");
	print_ip();
	ncPrintChar('\n');
	infoReg();
	char c ;
	sys_read(0, &c, 1);
	ncClear();
}

void invalid_OPCODE() {
	ncPrintChar('\n');
	ncPrintFormat("Invalid OPCODE ",RED,BLACK);
	ncPrint("Instruction Pointer: ");
	print_ip();
	ncPrintChar('\n');
	infoReg();
	char c ;
	sys_read(0, &c, 1);
	ncClear();
}