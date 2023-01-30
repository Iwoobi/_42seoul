#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* a;
	AForm* b;
	AForm* c;
	AForm* d;
	a = someRandomIntern.makeForm("presidential pardon", "a");
	b = someRandomIntern.makeForm("robotomy request", "b");
	c = someRandomIntern.makeForm("shrubbery creation", "c");
	d = someRandomIntern.makeForm("aaaa", "d");
	if (d == NULL)
		std::cout << "d ERROE\n"; 

	Bureaucrat f("c",6);
	f.signForm(*a);
	f.signForm(*c);
	f.executeForm(*a);
	std::cout << "=======1=======\n";
	f.executeForm(*b);
	std::cout << "=======2=======\n";
	f.executeForm(*c);


	std::cout << "\n\n===============\n";
	std::cout << *a;
	std::cout << *b;
	std::cout << *c;
	
}