#include "grammar.h"
#include <cmath>

const std::map<std::string, struct Data>	Grammar::grammar = {
	{"+", {2, 2, true}},
	{"-", {2, 2, true}},
	{"*", {3, 2, true}},
	{"/", {3, 2, true}},
	{"^", {4, 2, false}},
	{"=", {1, 2, false}},
	{"min", {1, 2, true}},
	{"max", {1, 2, true}},
	{"sqrt", {1, 1, true}},
};

using namespace std;

static inline void	translate(Environment &env, std::string &a)
{
	if (!Grammar::isDigit(a))
		a = std::to_string(env.evaluate(a));
}

const map<string, function<string(Environment&, vector<string>)>>	Grammar::operations = {
	{"+", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args)
				translate(env, i);
			return to_string(stod(args[0]) + stod(args[1]));
		}},
	{"-", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(stod(args[0]) - stod(args[1]));
		}},
	{"*", [] (Environment &env, vector<string> args) -> string
		{ 
			for (auto &i : args) translate(env, i);
			return to_string(stod(args[0]) * stod(args[1]));
		}},
	{"/", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(stod(args[0]) / stod(args[1]));
		}},
	{"^", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(pow(stod(args[0]), stod(args[1])));
		}},
	{"=", [] (Environment &env, vector<string> args) -> string
		{
			if (args[0] == args[1])
				env.remove(args[0]);
			else
				env.assign(args[0], args[1]);
			return args[1];
		}},
	{"min", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return stod(args[0]) < stod(args[1]) ? args[0] : args[1];
		}},
	{"max", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return stod(args[0]) > stod(args[1]) ? args[0] : args[1];
		}},
	{"sqrt", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(sqrt(stod(args[0])));
		}},
};
