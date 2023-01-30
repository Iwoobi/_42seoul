#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", -1);
	a.downgrade();
	std::cout << a;
	a.downgrade();
	std::cout << a;
	a.downgrade();
	std::cout << a;
	a.downgrade();
	std::cout << a;
	a.upgrade();
	std::cout << a;
	std::cout << "-----------------------" << std::endl;
	Bureaucrat b("a", 4);
	b.upgrade();
	b.upgrade();
	b.upgrade();
	std::cout << b;
	std::cout << "- - - - - - - - - - - -" << std::endl;
	b.upgrade();
	std::cout << b;
	b.downgrade();
	std::cout << b;
	std::cout << "-----------------------" << std::endl;
	Bureaucrat c("a", 145);
	c.downgrade();
	c.downgrade();
	c.downgrade();
	c.downgrade();
	c.downgrade();
	std::cout << c;
	std::cout << "- - - - - - - - - - - -" << std::endl;
	c.downgrade();
	std::cout << c;
	c.upgrade();
	std::cout << c;
	c.downgrade();
	std::cout << c;
	std::cout << "-----------------------" << std::endl;
	Bureaucrat d("a", 152);
	d.upgrade();
	d.upgrade();
	std::cout << d;
	d.downgrade();
}