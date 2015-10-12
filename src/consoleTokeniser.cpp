#include "consoleTokeniser.h"
#include <iostream>
#include "stringTokenizer.h"

std::string	ConsoleTokeniser::getNextToken(void)
{
	std::string	_line;
	if (_isEndFile && (!_stringParser || _stringParser->isEndLine())) {
		_stringParser = nullptr;
		return "";
	}
	if (!_stringParser || _stringParser->isEndLine()) {
		std::getline(std::cin, _line);
		if (!std::cin && _line == "") {
			_isEndFile = true;
			return "";
		} else if (!std::cin)
			_isEndFile = true;
	}
	if ((!_stringParser || _stringParser->isEndLine()) && _line != "")
		_stringParser = make_unique<StringTokenizer>(_line);
	else if (!_stringParser)
		return "";
	return _stringParser->getNextToken();
}

void		ConsoleTokeniser::clear(void)
{
	_stringParser = nullptr;
	_isEndFile = false;
}

bool		ConsoleTokeniser::isEndLine(void) const
{
	return !_stringParser || _stringParser->isEndLine();
}

bool		ConsoleTokeniser::isEndFile(void) const
{
	return _isEndFile;
}
