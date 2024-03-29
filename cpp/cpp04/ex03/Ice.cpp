#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice( const Ice & src )
{
	this->type = src.getType();
}


// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

Ice::~Ice()
{
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}
AMateria* Ice::clone() const
{
	AMateria *tmp;
	tmp = new Ice;
	return tmp;
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */