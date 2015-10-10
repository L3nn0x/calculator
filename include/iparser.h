
#ifndef _IPARSER_H_
# define _IPARSER_H_

#include "tokeniser.h"
#include <queue>
#include <string>
#include "memory.h"

class	IParser
{
	public:
		virtual std::queue<std::string>	parse(std::shared_ptr<ITokeniser>) = 0;
};

#endif /* !_IPARSER_H_ */
