
#ifndef _TOKENISER_H_
# define _TOKENISER_H_

#include <string>

class	ITokeniser
{
	public:
		virtual std::string	getNextToken(void) = 0;
		virtual void		clear(void) = 0;
		virtual bool		isEndLine(void) const = 0;
		virtual bool		isEndFile(void) const = 0;
};

#endif /* !_TOKENISER_H_ */
