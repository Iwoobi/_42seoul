#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "make WrongCat" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << "make WrongCat" << type << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	this->type = src.type;
	std::cout << "copy WrongCat " << src.type << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "delete WrongCat" << std::endl; 	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	} 
	return *this;
}

void		WrongCat::makeSound() const
{
	std::cout << "make a WrongCat sound " << this->type << std::endl;
}

// std::string	WrongCat::getType() const
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