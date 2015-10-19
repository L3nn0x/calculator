#include "compute.h"
#include <string>
#include "grammar.h"
#include "exceptions.h"
#include "stringTokenizer.h"
#include "memory.h"
#include <algorithm>

#define isZero(x) (std::stod(x) >= -0.0000001f && std::stod(x) <= 0.0000001f)

Compute::Compute(std::shared_ptr<ITokeniser> in, std::shared_ptr<IOutput> out,
				std::unique_ptr<IParser> parser) : _isDebug(false), _in(in),
				_out(out),
				_parser(std::move(parser)), _env(this)
{}

void	Compute::setDebug(void)
{
	_isDebug = true;
}

double	Compute::computeLine(std::string line)
{
	std::queue<std::string>	tokens = _parser->parse(line == "" ?
									_in : make_unique<StringTokenizer>(line));
	std::stack<std::string>	numbers;
	if (!tokens.size())
		throw NoDataException();
	while (tokens.size()) {
		if (_isDebug)
			printState(tokens, numbers);
		std::string	tmp = tokens.front();
		tokens.pop();
		if (!Grammar::isDigit(tmp) && Grammar::isGrammar(tmp)) {
			if (numbers.size() < (unsigned)Grammar::nbOperators(tmp))
				throw NoOperandException();
			if (tmp == "/" && Grammar::isDigit(numbers.top()) && isZero(numbers.top()))
				throw ZeroDivisionException();
			std::vector<std::string>	args;
			for (int i = 0; i < Grammar::nbOperators(tmp); ++i) {
				args.push_back(numbers.top());
				numbers.pop();
			}
			std::reverse(args.begin(), args.end());
			std::string	res = Grammar::getOp(tmp, _env, args);
			if (res != "")
				numbers.push(res);
		} else
			numbers.push(tmp);
	}
	if (!numbers.size())
		throw NoCalculationException();
	if (!Grammar::isDigit(numbers.top()))
		return _env.evaluate(numbers.top());
	return std::stod(numbers.top());
}

void	Compute::printState(std::queue<std::string> tokens, std::stack<std::string> numbers)
{
	_out->print("-------New state--------");
	_out->print("Current queue :");
	while (tokens.size()) {
		_out->print(tokens.front());
		tokens.pop();
	}
	_out->print("Current stack : ");
	while (numbers.size()) {
		_out->print(numbers.top());
		numbers.pop();
	}
}
