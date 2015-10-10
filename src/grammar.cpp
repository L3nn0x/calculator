#include "grammar.h"
#include <cmath>

const std::map<std::string, std::pair<int, bool>>	Grammar::grammar = {
	{"+", std::make_pair(2, true)},
	{"-", std::make_pair(2, true)},
	{"*", std::make_pair(3, true)},
	{"/", std::make_pair(3, true)},
	{"^", std::make_pair(4, false)},
};

const std::map<std::string, std::function<double(double, double)>>	Grammar::operations = {
	{"+", [] (double a, double b) -> double { return a + b; }},
	{"-", [] (double a, double b) -> double { return a - b; }},
	{"*", [] (double a, double b) -> double { return a * b; }},
	{"/", [] (double a, double b) -> double { return a / b; }},
	{"^", [] (double a, double b) -> double { return std::pow(a, b); }}
};
