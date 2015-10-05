#include "shutingyard.h"
#include "grammar.h"
#include <vector>

std::stack<std::string>	ShutingYard::parse(std::shared_ptr<ITokeniser> tok)
{
	std::stack<std::string>	result;
	std::stack<std::string>	ops;
	std::vector<std::string>	queue;

	do
	{
		auto	token = tok->getNextToken();
		if (Grammar::isDigit(token))
			queue.push_back(token);
		else if (Grammar::isGrammar(token)) {

		}
	} while (!tok->isEndLine());
	return result;
}
