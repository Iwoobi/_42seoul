#include <iostream>
#include "Iter.hpp"
template <typename T>
void printf(T &a)
{
	std::cout << a << " ";
}
template <typename T>
void plus(T &a)
{
	a += 1;
}

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	char b[6] = "abcde";
	iter(a, 5, &printf);
	iter(a, 5, &plus);
	std::cout << "\n";
	iter(a, 5, &printf);

	std::cout << "\n";
	iter(b, 5, &printf);
	iter(b, 5, &plus);
	std::cout << "\n";
	iter(b, 5, &printf);

}