
#ifndef _IOUTPUT_H_
# define _IOUTPUT_H_

#include <string>

class	IOutput
{
	public:
		virtual void	print(std::string const&) = 0;
};

#endif /* !_IOUTPUT_H_ */
