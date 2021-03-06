
#ifndef _COMPUTE_H_
# define _COMPUTE_H_

#include "tokeniser.h"
#include "ioutput.h"
#include "iparser.h"
#include "memory.h"
#include <stack>
#include <string>
#include "environment.h"

class	Compute
{
	public:
		Compute(std::shared_ptr<ITokeniser>, std::shared_ptr<IOutput>,
				std::unique_ptr<IParser>);

		double	computeLine(std::string line = "");

		void	setDebug(void);

	private:
		void						printState(std::queue<std::string>, std::stack<std::string>);
		bool						_isDebug;
		std::shared_ptr<ITokeniser>	_in;
		std::shared_ptr<IOutput>	_out;
		std::unique_ptr<IParser>	_parser;
		Environment					_env;
};

#endif /* !_COMPUTE_H_ */
