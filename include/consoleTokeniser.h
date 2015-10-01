
#ifndef _CONSOLETOKENISER_H_
# define _CONSOLETOKENISER_H_

#include "tokeniser.h"
#include <string>

class	ConsoleTokeniser : public ITokeniser
{
	public:
		virtual std::string	getNextToken(void);
		virtual bool		isEndLine(void) const;
		virtual bool		isEndFile(void) const;

	private:
		std::string			_line;
		bool				_isEndLine;
		bool				_isEndFile;
		bool				_wasOperator;
};

#endif /* !_CONSOLETOKENISER_H_ */
