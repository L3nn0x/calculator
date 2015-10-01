
#ifndef _CONSOLEOUTPUT_H_
# define _CONSOLEOUTPUT_H_

#include "ioutput.h"

class	ConsoleOutput : public IOutput
{
	public:
		virtual void	print(std::string const &);
};

#endif /* !_CONSOLEOUTPUT_H_ */
