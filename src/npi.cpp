#include "npi.h"
#include <vector>
#include "exceptions.h"
#include "grammar.h"

std::queue<std::string>	NPI::parse(std::shared_ptr<ITokeniser> tok)
{
	std::queue<std::string>	result;
	do
	{
		std::string	blob = tok->getNextToken();
		if (blob != "" && !Grammar::isDigit(blob) && !Grammar::isGrammar(blob)) {
			tok->clear();
			throw NotGrammarException();
		}
		result.push(blob);
	} while (!tok->isEndLine());
	return result;
}
