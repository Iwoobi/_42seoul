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

Form*	Intern::makeForm(std::string form, std::string target)
{
	std::string	type[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};
	Form *tmp;
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
		if (tmp == NULL)
			throw NotExistException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(0);
	}
	return (tmp);
}
const char* Intern::NotExistException::what() const throw()
{
	return ("It's a Form that doesn't exist");
}
const char* Intern::MallocException::what() const throw()
{
	return ("malloc error");
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/


Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
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