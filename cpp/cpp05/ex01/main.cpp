#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Form a("a", -1);
	std::cout << a;
	std::cout << "-----------------------" << std::endl;
	Form b("a", 1);
	std::cout << b;
	std::cout << "-----------------------" << std::endl;
	Form c("a", 150);
	std::cout << c;
	std::cout << "-----------------------" << std::endl;
	Form d("a", 151);
	std::cout << d;
	std::cout << "-----------------------" << std::endl;
	Bureaucrat f("a", -1);
	f.signForm(b);
	std::cout << b;
	std::cout << "--------222222------" << std::endl;
	Bureaucrat f1("a", 3);
	f1.signForm(c);
	std::cout << c;
	std::cout << "--------3333333------" << std::endl;
	f1.signForm(b);
	std::cout << b;
	std::cout << "--------444444------" << std::endl;

	f1.signForm(a);
	std::cout << a;
	
}