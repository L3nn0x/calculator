#include "stringTokenizer.h"
#include "grammar.h"

StringTokenizer::StringTokenizer(std::string const &line) : _line(line),
														_isEndLine(_line == ""),
														_wasOperator(false)
{}

std::string	StringTokenizer::getNextToken(void)
{
	if (_line == "") {
		_isEndLine = true;
		return "";
	}
	std::string	token;
	if (_wasOperator && Grammar::isDigit(_line)) {
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
	else if (Grammar::isGrammar(_line.substr(0, 1)) || Grammar::isParenthesis(_line.substr(0, 1))) {
		token = _line[0];
		_wasOperator = true;
		_line.erase(0, token.size());
	} else {
		token = _line.substr(0, _line.find_first_of(Grammar::getGrammar() + " \t"));
		_line.erase(0, token.size());
	}

	if (token == ",")
		_wasOperator = true;

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

void	StringTokenizer::clear(void)
{
	_line = "";
	_isEndLine = "";
}

bool	StringTokenizer::isEndFile(void) const
{
	return true;
}

bool	StringTokenizer::isEndLine(void) const
{
	return _isEndLine;
}
