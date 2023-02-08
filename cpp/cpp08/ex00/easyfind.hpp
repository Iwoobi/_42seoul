#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>

#include <algorithm>
template <typename T>
typename T::iterator easyfind(T& data, int val)
{
    typename T::iterator i;

    i = std::find(data.begin(), data.end(), val);
    return (i);
}

#endif
