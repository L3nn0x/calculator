#include "compute.h"
#include "npi.h"
#include "consoleTokeniser.h"
#include "consoleOutput.h"
#include "memory.h"
#include <cassert>
#include <iostream>

int	main()
{
	auto	tmp = make_unique<Compute>(make_unique<ConsoleTokeniser>(),
							make_unique<ConsoleOutput>(),
							make_unique<NPI>());
	assert(tmp && "ERROR CREATING OBJECT");
	tmp->setDebug();
	std::string	data("1 1 +\n");
	for (auto it = data.rbegin(); it != data.rend(); ++it)
		std::cin.putback(*it);
	tmp->computeLine();
};
