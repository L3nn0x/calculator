#include "npi.h"

std::queue<std::string>	NPI::parse(std::unique_ptr<ITokeniser> tok)
{
	std::queue<std::string>	result;
	while (!tok->isEndLine())
		result.push(tok->getNextToken());
	return result;
}
