#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure( const Cure & src )
{
	this->type = src.getType();
}


// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

Cure::~Cure()
{
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* tmp;
	tmp = new Cure;
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "’s wounds *"<<  std::endl;
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */