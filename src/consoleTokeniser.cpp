#include "consoleTokeniser.h"
#include <iostream>
#include "grammar.h"

std::string	ConsoleTokeniser::getNextToken(void)
{
	if (_isEndFile && _line == "")
		return "";
	if (_line == "") {
		std::getline(std::cin, _line);
		if (!std::cin && _line == "") {
			_isEndFile = true;
			return "";
		} else if (!std::cin)
			_isEndFile = true;
	}
	std::string	token;
	if ((_wasOperator && Grammar::isDigit(_line))
			|| Grammar::isDigit(_line)) {
		size_t	size;
		token = std::to_string(std::stod(_line, &size));
		if (token.find('.') != std::string::npos)
			while (*(token.end() - 1) == '0')
				token.pop_back();
		if (*(token.end() - 1) == '.')
			token.pop_back();
		_wasOperator = false;
		_line.erase(0, size);
	}
	else if (Grammar::isGrammar(_line.substr(0, 1))) {
		token = _line[0];
		_wasOperator = true;
		_line.erase(0, token.size());
	}
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
