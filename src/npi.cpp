#include "npi.h"
#include <vector>

std::stack<std::string>	NPI::parse(std::shared_ptr<ITokeniser> tok)
{
	std::stack<std::string>	result;
	std::vector<std::string>	tmp;
	do
	{
		std::string	blob = tok->getNextToken();
		tmp.push_back(blob);
	} while (!tok->isEndLine());
	for (auto it = tmp.rbegin(); it != tmp.rend(); ++it)
		result.push(*it);
	return result;
}
