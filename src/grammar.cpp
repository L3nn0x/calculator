#include "grammar.h"
#include <cmath>

const std::map<std::string, struct Data>	Grammar::grammar = {
	{"+", {2, 2, true}},
	{"-", {2, 2, true}},
	{"*", {3, 2, true}},
	{"/", {3, 2, true}},
	{"^", {4, 2, false}},
	{"=", {1, 2, false}},
	{"min", {6, 2, false}},
	{"max", {6, 2, false}},
	{"sqrt", {6, 1, false}},
	{"cos", {6, 1, false}},
	{"sin", {6, 1, false}},
	{"tan", {6, 1, false}},
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
			if (args[0] == args[1]) {
				env.remove(args[0]);
				return "";
			} else
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
	{"cos", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(cos(stod(args[0])));
		}},
	{"sin", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(sin(stod(args[0])));
		}},
	{"tan", [] (Environment &env, vector<string> args) -> string
		{
			for (auto &i : args) translate(env, i);
			return to_string(tan(stod(args[0])));
		}},
};

bool	Grammar::isDigit(std::string const &c)
{
	return std::isdigit(c[0]) || (c[0] == '-' && std::isdigit(c[1]));
}

bool	Grammar::isGrammar(std::string const &c)
{
	std::string	tmp(c);
	tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [](char x) { return x == ' ' || x == '\t';}), tmp.end());
	return Grammar::grammar.find(tmp) != Grammar::grammar.end();
}

bool	Grammar::isFunction(std::string const &c)
{
	std::string	tmp(c);
	tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [] (char x) { return x == ' ' || x == '\t';}), tmp.end());
	if (tmp == "" || Grammar::isDigit(tmp) || tmp.find_first_of(Grammar::getGrammar()) != std::string::npos)
		return false;
	return true;
}

bool	Grammar::isParenthesis(std::string const &c)
{
	return c == "(" || c == ")";
}

bool	Grammar::isLeft(std::string const &c)
{
	if (!Grammar::isGrammar(c))
		/* throw NotGrammarException(); */
		return false;
	return static_cast<std::map<std::string, struct Data>>(Grammar::grammar)[c].leftAssociative;
}

int	Grammar::priority(std::string const &c)
{
	if (!Grammar::isGrammar(c))
		/* throw NotGrammarException(); */
		return 5;
	return static_cast<std::map<std::string, struct Data>>(Grammar::grammar)[c].precedence;
}

int	Grammar::nbOperators(std::string const &c)
{
	if (!Grammar::isGrammar(c))
		throw NotGrammarException();
	return static_cast<std::map<std::string, struct Data>>(Grammar::grammar)[c].nbOperators;
}

std::string	Grammar::getOp(std::string const &c, Environment &env, std::vector<std::string> args)
{
	if (!Grammar::isGrammar(c))
		throw NotGrammarException();
	return static_cast<std::map<std::string, std::function<std::string(Environment&,std::vector<std::string>)>>>(Grammar::operations)[c](env, args);
}

std::string	Grammar::getGrammar(void)
{
	return "+-*/^=(),";
}

