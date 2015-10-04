#include "compute.h"
#include <string>
#include <stack>
#include "grammar.h"
#include <vector>
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
	std::stack<std::string>	tokens = _parser->parse(_in);
	std::vector<double>	op;
	if (!tokens.size())
		throw NoDataException();
	while (tokens.size()) {
		if (_isDebug)
			printState(tokens);
		std::string	tmp = tokens.top();
		tokens.pop();
		if (!Grammar::isDigit(tmp[1]) && Grammar::isGrammar(tmp[0])) {
			if (op.size() < 2)
				throw NoOperandException();
			switch (tmp[0]) {
				case '+':
					tokens.push(std::to_string(op[0] + op[1]));
					break;
				case '-':
					tokens.push(std::to_string(op[0] - op[1]));
					break;
				case '*':
					tokens.push(std::to_string(op[0] * op[1]));
					break;
				case '/':
					if (op[1] >= -0.0000001f && op[1] <= 0.0000001f)
						throw ZeroDivisionException();
					tokens.push(std::to_string(op[0] / op[1]));
					break;
			}
			op.clear();
		} else if (Grammar::isDigit(tmp[0]) || Grammar::isDigit(tmp[1]))
			op.push_back(std::stod(tmp));
	}
	if (!op.size())
		throw NoDataException();
	return op[0];
}

void	Compute::printState(std::stack<std::string> tokens)
{
	_out->print("Current state :");
	while (tokens.size()) {
		_out->print(tokens.top());
		tokens.pop();
	}
}
