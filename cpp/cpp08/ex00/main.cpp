
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>   

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;
	int val = 111;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < d.size(); i++)
	{
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < l.size(); i++)
	{
		std::cout << l[i] << " ";
	}
	std::cout << "\n";
	std::cout << *easyfind(v, val) << "\n";
	std::cout << *easyfind(d, val) << "\n";
	std::cout << *easyfind(l, val) << "\n";

	if (v.end() == easyfind(v, val))
		std::cout << "not found\n";
	else
		std::cout << "found\n";
	if (d.end() == easyfind(d, val))
		std::cout << "not found\n";
	else
		std::cout << "found\n";
	if (l.end() == easyfind(l, val))
		std::cout << "not found\n";
	else
		std::cout << "found\n";
}