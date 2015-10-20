#include "environment.h"
#include "exceptions.h"
#include "compute.h"

Environment::Environment(Compute *callback) : _callback(callback)
{
	assert(_callback && "Callback can't be null");
	_expressions["PI"] = "3.141592653589793";
}

void	Environment::assign(std::string const &var, std::string const &exp)
{
	_expressions[var] = exp;
}

double	Environment::evaluate(std::string const &var)
{
	if (_expressions.find(var) == _expressions.end())
		throw NoExpressionException();
	return _callback->computeLine(_expressions[var]);
}

void	Environment::remove(std::string const &var)
{
	auto	it = _expressions.find(var);
	if (it == _expressions.end())
		throw NoExpressionException();
	_expressions.erase(it);
}
