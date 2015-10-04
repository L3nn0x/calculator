#include "npi.h"
#include "memory.h"
#include <cassert>
#include <vector>
#include <stack>
#include "consoleTokeniser.h"
#include <iostream>

int	main()
{
	auto	tmp = make_unique<NPI>();
	assert(tmp && "ERROR CREATING NPI");

	std::string	data("1 2 + 4 *\n");
	std::vector<std::string>	test{"1", "2", "+", "4", "*"};
	for (auto it = data.rbegin(); it != data.rend(); ++it)
		std::cin.putback(*it);
	auto	res = tmp->parse(make_unique<ConsoleTokeniser>());
	assert(res.size() == test.size() && "NOT THE RIGHT NUMBER OF TOKENS!");
	int	i = 0;
	while (res.size()) {
		std::cout << "Test " << res.top() << " " << test[i] << std::endl;
		assert(res.top() == test[i] && "NOT THE GOOD TOKEN!");
		++i;
		res.pop();
	}
	std::cout << "OK" << std::endl;
}
