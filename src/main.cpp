#include "compute.h"
#include "consoleOutput.h"
#include "consoleTokeniser.h"
#include "npi.h"
#include "shutingyard.h"
#include "memory.h"
#include <iostream>
#include "exceptions.h"
#include <iomanip>
#include <cstring>

int	main()
{
	auto	input = std::make_shared<ConsoleTokeniser>();
	auto	output = std::make_shared<ConsoleOutput>();
	Compute	compute(input, output, make_unique<ShutingYard>());
	compute.setDebug();
	std::cout << "> ";
	while (!input->isEndFile()) {
		try {
		std::cout << ">> " << compute.computeLine() << std::endl;
		} catch (NoDataException &e) {
			std::cout << "Bye" << std::endl;
			return 0;
		} catch (std::exception &e) {
			if (strcmp(const_cast<char*>(e.what()), ""))
				std::cout << e.what() << std::endl;
		}
		std::cout << "> ";
	}
}
