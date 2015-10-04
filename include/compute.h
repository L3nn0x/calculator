
#ifndef _COMPUTE_H_
# define _COMPUTE_H_

#include "tokeniser.h"
#include "ioutput.h"
#include "iparser.h"
#include "memory.h"

class	Compute
{
	public:
		Compute(std::shared_ptr<ITokeniser>, std::shared_ptr<IOutput>,
				std::unique_ptr<IParser>);

		double	computeLine(void);

		void	setDebug(void);

	private:
		void						printState(std::stack<std::string>);
		bool						_isDebug;
		std::shared_ptr<ITokeniser>	_in;
		std::shared_ptr<IOutput>	_out;
		std::unique_ptr<IParser>	_parser;
};

#endif /* !_COMPUTE_H_ */
