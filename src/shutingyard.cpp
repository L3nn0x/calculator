#include "shutingyard.h"
#include "grammar.h"
#include <stack>

#define isstrictlower(x, y) (Grammar::priority(x) < Grammar::priority(y))
#define islower(x, y) (Grammar::priority(x) <= Grammar::priority(y))

std::queue<std::string>	ShutingYard::parse(std::shared_ptr<ITokeniser> tok)
{
	std::queue<std::string>	F;
	std::stack<std::string>	P;

	do
	{
		auto	token = tok->getNextToken();
		if (Grammar::isDigit(token))
			F.push(token);
		else if (Grammar::isFunction(token))
			P.push(token);
		else if (token == ",") {
			while (P.size() && P.top() != "(") {
				F.push(P.top());
				P.pop();
			}
		} else if (Grammar::isGrammar(token)) {
			while (P.size()
					&& P.top() != "(" && (Grammar::isFunction(P.top()) || ((Grammar::isLeft(token) && islower(token, P.top()))
						|| (!Grammar::isLeft(token) && isstrictlower(token, P.top()))))) {
				F.push(P.top());
				P.pop();
			}
			P.push(token);
		} else if (token == "(") {
			P.push(token);
		} else if (token == ")") {
			while (P.top() != "(") {
				F.push(P.top());
				P.pop();
			}
			P.pop();
		}
	} while (!tok->isEndLine());
	while (P.size()) {
		F.push(P.top());
		P.pop();
	}
	return F;
}
