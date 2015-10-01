#include "consoleTokeniser.h"
#include <iostream>
#include <cctype>

static const char	grammar[] = {'+', '-', '*', '/', '(', ')'};

static bool	isGrammar(const char c)
{
	for (size_t i = 0; i < sizeof(grammar) / sizeof(grammar[0]); ++i)
		if (c == grammar[i])
			return true;
	return false;
}

std::string	ConsoleTokeniser::getNextToken(void)
{
	if (_line == "") {
		std::getline(std::cin, _line);
		if (_line == "") {
			_isEndFile = true;
			return "";
		}
	}
	std::string	token;
	if ((_wasOperator && _line[0] == '-' && std::isdigit(_line[1]))
			|| std::isdigit(_line[0])) {
		token = std::to_string(std::stoi(_line));
		_wasOperator = false;
	}
	else if (isGrammar(_line[0])) {
		token = _line[0];
		_wasOperator = true;
	}
	_line.erase(0, token.size());
	int	i = 0;
	while (_line[i] == ' ' || _line[i] == '\t')
		++i;
	if (i)
		_line.erase(0, i);
	if (_line == "")
		_isEndLine = true;
	else
		_isEndLine = false;
	return token;
}

bool		ConsoleTokeniser::isEndLine(void) const
{
	return _isEndLine;
}

bool		ConsoleTokeniser::isEndFile(void) const
{
	return _isEndFile;
}
