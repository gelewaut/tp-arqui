#include <naiveConsole.h>
#include <sysCalls.h>
#include <inforeg.h>

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 0

void zero_division();
void invalid_OPCODE();

void exceptionDispatcher(int exception)
{
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if (exception == OPCODE_EXCEPTION_ID)
		invalid_OPCODE();
	// printRegs();
}

void zero_division()
{
	ncPrintChar('\n');
	ncPrintFormat("Division By Zero ", RED, BLACK);
	ncPrintChar('\n');
}

void invalid_OPCODE()
{
	ncPrintChar('\n');
	ncPrintFormat("Invalid OPCODE ", RED, BLACK);
	ncPrintChar('\n');
}