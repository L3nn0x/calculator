
#ifndef _CONSOLETOKENISER_H_
# define _CONSOLETOKENISER_H_

#include "tokeniser.h"
#include <string>
#include "memory.h"
#include "stringTokenizer.h"

class	ConsoleTokeniser : public ITokeniser
{
	public:
		virtual std::string	getNextToken(void);
		virtual void		clear(void);
		virtual bool		isEndLine(void) const;
		virtual bool		isEndFile(void) const;

	private:
		std::unique_ptr<StringTokenizer>	_stringParser;
		std::string							_line;
		bool								_isEndFile;
};

#endif /* !_CONSOLETOKENISER_H_ */
