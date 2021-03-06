
#ifndef _ENVIRONMENT_H_
# define _ENVIRONMENT_H_

#include <string>
#include <map>
#include <cassert>

class	Compute;

class	Environment
{
	public:
		Environment(Compute *callback);

		void	assign(std::string const &var, std::string const &exp);
		void	remove(std::string const &var);

		double	evaluate(std::string const &var);

	private:
		std::map<std::string, std::string>	_expressions;
		Compute								*_callback;
};

#endif /* !_ENVIRONMENT_H_ */
