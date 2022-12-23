#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "make Cat" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "make Cat" << type << std::endl;
}

Cat::Cat( const Cat & src )
{
	this->type = src.type;
	this->brain = src.brain;
	std::cout << "copy Cat " << src.type << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->brain;
	std::cout << "delete Cat" << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Asdsad\n" <<std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
		this->brain = rhs.brain;
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