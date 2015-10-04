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
		std::cout << ">> " << std::setprecision(2) << compute.computeLine() << std::endl;
		} catch (NoDataException &e) {
			std::cout << "Bye" << std::endl;
			return 0;
		} catch (NoOperandException &e) {
			std::cout << e.what() << std::endl;
		} catch (ZeroDivisionException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "> ";
	}
}
