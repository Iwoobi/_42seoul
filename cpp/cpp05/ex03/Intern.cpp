#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string	type[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};
	AForm *tmp;
	int i = 0;
	for (;i < 3; i++)
	{
		if (type[i] == form)
			break;
	}
	try
	{
		switch (i)
		{
			case 0:
				tmp = new ShrubberyCreationForm(target);
				break;
			case 1:
				tmp = new RobotomyRequestForm(target);
				break;
			case 2:
				tmp = new PresidentialPardonForm(target);
				break;
			default:
				throw NotExistException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (tmp);
}
const char* Intern::NotExistException::what() const throw()
{
	return ("It's a Form that doesn't exist");
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/


Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		return *this;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */