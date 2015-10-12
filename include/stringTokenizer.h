
#ifndef _STRINGTOKENIZER_H_
# define _STRINGTOKENIZER_H_

#include "tokeniser.h"

class	StringTokenizer : public ITokeniser
{
	public:
		StringTokenizer(std::string const &line);

		virtual std::string	getNextToken(void);
		virtual void		clear(void);
		virtual bool		isEndLine(void) const;
		virtual bool		isEndFile(void) const;

	private:
		std::string	_line;
		bool		_isEndLine;
		bool		_wasOperator;
};

#endif /* !_STRINGTOKENIZER_H_ */
