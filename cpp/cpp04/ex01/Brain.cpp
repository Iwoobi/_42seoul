#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "create Brain" << std::endl;
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "Copy Brain" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "delete Brain" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
		// *this = rhs;
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