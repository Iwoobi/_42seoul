#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Form a("b",-1);
	Bureaucrat b("c",1);
	b.downgrade();
	b.signForm(a);
	std::cout << a;
	
	
}