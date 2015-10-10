#include "shutingyard.h"
#include "memory.h"
#include <cassert>
#include <vector>
#include <queue>
#include "consoleTokeniser.h"
#include <iostream>

int	main()
{
	auto	tmp = make_unique<ShutingYard>();
	assert(tmp && "ERROR CREATING NPI");

	std::string	data("1 + 2 - 3 * (4 + 2)\n");
	std::vector<std::string>	test{"1", "2", "+", "4", "2", "+", "3", "*", "-"};
	for (auto it = data.rbegin(); it != data.rend(); ++it)
		std::cin.putback(*it);
	auto	res = tmp->parse(make_unique<ConsoleTokeniser>());
	assert(res.size() == test.size() && "NOT THE RIGHT NUMBER OF TOKENS!");
	int	i = 0;
	while (res.size()) {
		std::cout << "Test " << res.front() << " " << test[i] << std::endl;
		assert(res.front() == test[i] && "NOT THE GOOD TOKEN!");
		++i;
		res.pop();
	}
	std::cout << "OK" << std::endl;
}
