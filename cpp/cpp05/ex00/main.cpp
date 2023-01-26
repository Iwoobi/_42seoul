#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", -1);
	a.downgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	
	a.downgrade();
	std::cout << a;
	a.downgrade();
	std::cout << a;
	a.downgrade();
	std::cout << a;
}