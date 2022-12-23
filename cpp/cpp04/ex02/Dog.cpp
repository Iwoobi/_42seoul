#include "Dog.hpp"
#include "Brain.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "make Dog" << std::endl;
}
Dog::Dog(std::string type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "make Dog " << type << std::endl;
}

Dog::Dog( const Dog & src )
{
	this->type = src.type;
	std::cout << "copy Dog " << src.type << std::endl;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->brain;
	std::cout << "delete Dog" << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

void		Dog::makeSound() const
{
	std::cout << "make a Dog sound " << this->type << std::endl;
}

// std::string	Dog::getType() const
// {
// 	return (this->type);
// }




/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */