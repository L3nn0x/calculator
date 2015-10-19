#include "grammar.h"
#include <cmath>

const std::map<std::string, struct Data>	Grammar::grammar = {
	{"+", {2, 2, true}},
	{"-", {2, 2, true}},
	{"*", {3, 2, true}},
	{"/", {3, 2, true}},
	{"^", {4, 2, false}},
	{"=", {1, 2, false}},
	{"min", {5, 2, true}},
	{"max", {5, 2, true}},
	{"sqrt", {5, 1, true}},
};

using namespace std;

static inline void	translate(Environment &env, std::string &a, std::string &b)
{
	if (a != "" && !Grammar::isDigit(a))
		a = std::to_string(env.evaluate(a));
	if (b != "" && !Grammar::isDigit(b))
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
			if (a == b)
				env.remove(a);
			else
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
	{"sqrt", [] (Environment &env, string a, string b) -> string
		{
			translate(env, a, b);
			return to_string(sqrt(stod(b)));
		}},
};
