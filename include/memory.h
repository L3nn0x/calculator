
#ifndef _MEMORY_H_
# define _MEMORY_H_

#include <memory>

template <typename T, typename ...Args>
std::unique_ptr<T>	make_unique(Args&& ...args)
{
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif /* !_MEMORY_H_ */
