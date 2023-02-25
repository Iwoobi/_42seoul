#include "easyfind.hpp"
#include <vector>
#include <list>
int main(void)
{
	std::vector<int> v;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}
    std::vector<int>::iterator v_i;
    std::list<int>::iterator l_i;
    v_i = easyfind(v, 10);
    l_i = easyfind(l, 10);
    if (v_i == v.end())
    {
        std::cout << "v\n";
    }
    if (l_i == l.end())
    {
        std::cout << "l\n";
    }
}