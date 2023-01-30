#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	PresidentialPardonForm a("a");
	RobotomyRequestForm	b("b");
	ShrubberyCreationForm c("c");

	Bureaucrat f("c",6);
	f.signForm(a);
	f.signForm(c);
	f.executeForm(a);
	std::cout << "=======1=======\n";
	f.executeForm(b);
	std::cout << "=======2=======\n";
	f.executeForm(c);


	std::cout << "\n\n===============\n";
	std::cout << a;
	std::cout << b;
	std::cout << c;
	
}