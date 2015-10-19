
#ifndef _GRAMMAR_H_
# define _GRAMMAR_H_

#include <cctype>
#include <string>
#include <map>
#include <utility>
#include "exceptions.h"
#include <algorithm>
#include <functional>
#include "environment.h"

struct	Data
{
	int		precedence;
	int		nbOperators;
	bool	leftAssociative;
};

class	Grammar
{
	public:
		static bool	isDigit(std::string const &c);

		static bool	isGrammar(std::string const &c);

		static bool	isFunction(std::string const &c);

		static bool	isParenthesis(std::string const &c);

		static bool	isLeft(std::string const &c);

		static int	priority(std::string const &c);

		static int	nbOperators(std::string const &c);

		static std::string	getOp(std::string const &c, Environment &env, std::vector<std::string> args);

		static std::string	getGrammar(void);

	private:
		static const std::map<std::string, struct Data>	grammar;
		static const std::map<std::string, std::function<std::string(Environment&, std::vector<std::string>)>>	operations;
};

#endif /* !_GRAMMAR_H_ */
