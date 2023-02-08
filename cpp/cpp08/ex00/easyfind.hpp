#ifndef EASTFIND_HPP
# define EASTFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T array, int val)
{
	typename T::iterator iter;
	iter = std::find(array.begin(), array.end(), val);
	return (iter);
}


#endif 