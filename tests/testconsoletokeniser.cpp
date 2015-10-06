#include "consoleTokeniser.h"
#include "memory.h"
#include <iostream>
#include <cassert>
#include <vector>

int	main()
{
	std::unique_ptr<ITokeniser>	tmp = make_unique<ConsoleTokeniser>();
	assert(tmp && "ERROR CREATING TOKENISER");
	std::string	data("1 2 - \t8 *7 3/()\n");
	std::vector<std::string>	test{"1", "2", "-", "8", "*", "7", "3", "/", "(", ")"};
	for (auto it = data.rbegin(); it != data.rend(); ++it)
		std::cin.putback(*it);
	size_t	i = 0;
	while (i < test.size() && !tmp->isEndFile()) {
		std::string	res = tmp->getNextToken();
		std::string	print("Test : ");
		print = print + "\"" + test[i] + "\" : \"" + res + "\"";
		std::cout << print << std::endl;
		assert(test[i] == res);
		++i;
	}
	std::cout << "OK" << std::endl;
}
