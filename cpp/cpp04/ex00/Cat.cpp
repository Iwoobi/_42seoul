#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "make Cat" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "make Cat" << type << std::endl;
}

Cat::Cat( const Cat & src )
{
	this->type = src.type;
	std::cout << "copy Cat " << src.type << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "delete Cat" << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	} 
	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "make a Cat sound " << this->type << std::endl;
}

// std::string	Cat::getType() const
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