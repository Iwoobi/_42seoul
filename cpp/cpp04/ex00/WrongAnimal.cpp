#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "make WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string src)
{
	this->type = src;
	std::cout << "make WrongAnimal " << src << std::endl;
}


WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	this->type = src.type;
	std::cout << "copy WrongAnimal " << src.type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "delete WrongAnimal" << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

void		 WrongAnimal::makeSound() const
{
	std::cout << "make a WrongAnimal sound " << this->type << std::endl;
}

std::string	 WrongAnimal::getType() const
{
	return (this->type);
}




/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */