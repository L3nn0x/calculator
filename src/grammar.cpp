#include "grammar.h"
#include <cmath>

const std::map<std::string, std::pair<int, bool>>	Grammar::grammar = {
	{"+", std::make_pair(2, true)},
	{"-", std::make_pair(2, true)},
	{"*", std::make_pair(3, true)},
	{"/", std::make_pair(3, true)},
	{"^", std::make_pair(4, false)},
	{"=", std::make_pair(1, false)},
	{"min", std::make_pair(5, true)},
	{"max", std::make_pair(5, true)},
};

using namespace std;

static inline void	translate(Environment &env, std::string &a, std::string &b)
{
	if (!Grammar::isDigit(a))
		a = std::to_string(env.evaluate(a));
	if (!Grammar::isDigit(b))
		b = std::to_string(env.evaluate(b));
}

const map<string, function<string(Environment&, string, string)>>	Grammar::operations = {
	{"+", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return to_string(stod(a) + stod(b));
		}},
	{"-", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return to_string(stod(a) - stod(b));
		}},
	{"*", [] (Environment &env, string a, string b) -> string
		{ 
			translate(env, a, b);
			return to_string(stod(a) * stod(b));
		}},
	{"/", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return to_string(stod(a) / stod(b));
		}},
	{"^", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return to_string(pow(stod(a), stod(b)));
		}},
	{"=", [] (Environment &env, string a, string b) -> string
		{
			env.assign(a, b);
			return b;
		}},
	{"min", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return stod(a) < stod(b) ? a : b;
		}},
	{"max", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return stod(a) > stod(b) ? a : b;
		}},
};
