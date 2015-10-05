#include "compute.h"
#include "consoleOutput.h"
#include "consoleTokeniser.h"
#include "npi.h"
#include "memory.h"
#include <iostream>
#include "exceptions.h"
#include <iomanip>

int	main()
{
	auto	input = std::make_shared<ConsoleTokeniser>();
	auto	output = std::make_shared<ConsoleOutput>();
	Compute	compute(input, output, make_unique<NPI>());
	std::cout << "> ";
	while (!input->isEndFile()) {
		try {
		std::cout << ">> " << compute.computeLine() << std::endl;
		} catch (NoDataException &e) {
			std::cout << "Bye" << std::endl;
			return 0;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "> ";
	}
}
