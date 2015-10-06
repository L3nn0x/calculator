#include "grammar.h"

const std::map<std::string, std::pair<int, bool>>	Grammar::grammar = {
	{"+", std::make_pair(2, true)},
	{"-", std::make_pair(2, true)},
	{"*", std::make_pair(3, true)},
	{"/", std::make_pair(3, true)},
	{"^", std::make_pair(4, false)},
};

