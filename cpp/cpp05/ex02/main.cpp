#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	PresidentialPardonForm a("a");
	RobotomyRequestForm	b("b");
	ShrubberyCreationForm c("c");

	Bureaucrat f("c",1);
	f.signForm(b);
	f.executeForm(b);
	f.signForm(a);
	std::cout << a;
	std::cout << b;
	std::cout << c;
	
}