#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 0

static void zero_division();
static void invalid_OPCODE();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if (exception == OPCODE_EXCEPTION_ID)
		invalid_OPCODE();
}

static void zero_division() {
	// Handler para manejar excepcíon
}

static void invalid_OPCODE() {
	// Handler para manejar excepcion
}