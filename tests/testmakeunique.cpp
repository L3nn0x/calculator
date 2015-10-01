#include "memory.h"
#include <cassert>
#include <iostream>

int	main()
{
	std::unique_ptr<int>	tmp = make_unique<int>(42);
	assert(tmp && "ERROR CREATING UNIQUE");
	assert(*tmp == 42 && "ERROR ASSIGING VALUE");
	std::cout << "OK" << std::endl;
}
