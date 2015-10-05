
#ifndef _SHUTINGYARD_H_
# define _SHUTINGYARD_H_

#include "iparser.h"

class	ShutingYard : public IParser
{
	public:
		virtual std::stack<std::string>	parse(std::shared_ptr<ITokeniser>);
};

#endif /* !_SHUTINGYARD_H_ */
