
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

class	Grammar
{
	public:
		static inline bool	isDigit(std::string const &c)
		{
			return std::isdigit(c[0]) || (c[0] == '-'
					&& std::isdigit(c[1]));
		}

		static bool	isGrammar(std::string const &c)
		{
			std::string	tmp(c);
			tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [](char x) { return x == ' ' || x == '\t';}), tmp.end());
			return Grammar::grammar.find(tmp) != Grammar::grammar.end();
		}

		static bool	isParenthesis(std::string const &c)
		{
			return c == "(" || c == ")";
		}

		static inline bool	isLeft(std::string const &c)
		{
			if (!Grammar::isGrammar(c))
				throw NotGrammarException();
			return static_cast<std::map<std::string, std::pair<int, bool>>>(Grammar::grammar)[c].second;
		}

		static inline int	priority(std::string const &c)
		{
			if (!Grammar::isGrammar(c))
				throw NotGrammarException();
			return static_cast<std::map<std::string, std::pair<int, bool>>>(Grammar::grammar)[c].first;
		}

		static inline std::string	getOp(std::string const &c, Environment &env, std::string a, std::string b)
		{
			if (!Grammar::isGrammar(c))
				throw NotGrammarException();
			return static_cast<std::map<std::string, std::function<std::string(Environment&,std::string, std::string)>>>(Grammar::operations)[c](env, a, b);
		}

		static inline std::string	getGrammar(void)
		{
			return "+-*/^=";
		}

	private:
		static const std::map<std::string, std::pair<int, bool>>	grammar;
		static const std::map<std::string, std::function<std::string(Environment&,std::string, std::string)>>	operations;
};

#endif /* !_GRAMMAR_H_ */
