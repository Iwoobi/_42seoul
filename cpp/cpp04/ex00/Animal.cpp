#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->type = "";
	std::cout << "make Animal" << std::endl;
}

Animal::Animal(std::string src)
{
	this->type = src;
	std::cout << "make Animal " << src << std::endl;
}


Animal::Animal( const Animal & src )
{
	this->type = src.type;
	std::cout << "copy Animal " << src.type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "delete Animal " << this->type << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

void		 Animal::makeSound() const
{
	std::cout << "make a Animal sound " << this->type << std::endl;
}

std::string	 Animal::getType() const
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