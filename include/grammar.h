
#ifndef _GRAMMAR_H_
# define _GRAMMAR_H_

#include <cctype>

class	Grammar
{
	public:
		static inline bool	isDigit(int c)
		{
			return std::isdigit(c);
		}

		template <typename T>
		static bool	isGrammar(T c)
		{
			static const char	grammar[] = {'+', '-', '*', '/'};
			for (size_t i = 0; i < sizeof(grammar) / sizeof(grammar[0]); ++i)
				if (c == grammar[i])
					return true;
			return false;
		}
};

#endif /* !_GRAMMAR_H_ */
