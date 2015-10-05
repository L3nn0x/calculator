
#ifndef _NODATAEXCEPTION_H_
# define _NODATAEXCEPTION_H_

#include <exception>

class	NoDataException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return "End of stream";
		}
};

class	NoOperandException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Not the right amout of operands";
		}
};

class	ZeroDivisionException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Division per zero";
		}
};

class	NotGrammarException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Not a grammar operand";
		}
};


#endif /* !_NODATAEXCEPTION_H_ */
