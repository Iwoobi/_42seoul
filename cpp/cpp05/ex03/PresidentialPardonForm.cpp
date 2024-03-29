#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
	AForm::setGrade(25);
	AForm::setGrade_exec(5);
	AForm::setName(target);
	AForm::setsign(0);
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	this->setsign(src.getSign());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setsign(rhs.getSign());
	}
	return *this;
}

void	PresidentialPardonForm::exec() const
{
	std::cout << " executed PresidentialPardonForm" << std::endl;
	std::cout << AForm::getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */