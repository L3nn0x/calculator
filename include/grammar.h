
#ifndef _GRAMMAR_H_
# define _GRAMMAR_H_

#include <cctype>
#include <string>
#include <map>
#include <utility>
#include "exceptions.h"
#include <algorithm>

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
			return Grammar::grammar.find(tmp) != Grammar::grammar.end() || c == "(" || c == ")";
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

	private:
		static const std::map<std::string, std::pair<int, bool>>	grammar;
};

#endif /* !_GRAMMAR_H_ */
