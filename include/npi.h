
#ifndef _NPI_H_
# define _NPI_H_

#include "iparser.h"

class	NPI : public IParser
{
	public:
		virtual std::stack<std::string>	parse(std::shared_ptr<ITokeniser>);
};

#endif /* !_NPI_H_ */
