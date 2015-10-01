#include "memory.h"
#include "consoleOutput.h"
#include <cassert>

int	main()
{
	auto	tmp = make_unique<ConsoleOutput>();
	assert(tmp && "ERROR CREATING OBJECT");
	tmp->print("OK");
}
