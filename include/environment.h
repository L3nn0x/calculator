
#ifndef _ENVIRONMENT_H_
# define _ENVIRONMENT_H_

#include <string>
#include <map>
#include <cassert>

class	Compute;

class	Environment
{
	public:
		Environment(Compute *callback) : _callback(callback) { assert(_callback && "Callback can't be null"); }

		void	assign(std::string const &var, std::string const &exp);

		double	evaluate(std::string const &var);

	private:
		std::map<std::string, std::string>	_expressions;
		Compute								*_callback;
};

#endif /* !_ENVIRONMENT_H_ */
