#include "compute.h"
#include <string>
#include "grammar.h"
#include "exceptions.h"

Compute::Compute(std::shared_ptr<ITokeniser> in, std::shared_ptr<IOutput> out,
				std::unique_ptr<IParser> parser) : _isDebug(false), _in(in),
				_out(out),
				_parser(std::move(parser))
{}

void	Compute::setDebug(void)
{
	_isDebug = true;
}

double	Compute::computeLine()
{
	std::queue<std::string>	tokens = _parser->parse(_in);
	std::stack<double>	numbers;
	if (!tokens.size())
		throw NoDataException();
	while (tokens.size()) {
		if (_isDebug)
			printState(tokens, numbers);
		std::string	tmp = tokens.front();
		tokens.pop();
		if (!Grammar::isDigit(tmp) && Grammar::isGrammar(tmp)) {
			if (numbers.size() < 2)
				throw NoOperandException();
			if (tmp == "/" && numbers.top() >= -0.0000001f && numbers.top() <= 0.0000001f)
				throw ZeroDivisionException();
			double	op = numbers.top();
			numbers.pop();
			double	res = Grammar::getOp(tmp, numbers.top(), op);
			numbers.pop();
			numbers.push(res);
		} else if (Grammar::isDigit(tmp))
			numbers.push(std::stod(tmp));
	}
	if (!numbers.size())
		throw NoDataException();
	return numbers.top();
}

void	Compute::printState(std::queue<std::string> tokens, std::stack<double> numbers)
{
	_out->print("Current state :");
	while (tokens.size()) {
		_out->print(tokens.front());
		tokens.pop();
	}
	_out->print("Current stack : ");
	while (numbers.size()) {
		_out->print(std::to_string(numbers.top()));
		numbers.pop();
	}
}
