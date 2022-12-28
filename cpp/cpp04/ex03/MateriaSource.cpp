#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	this->idx = 0;
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
		this->i_slot[i] = 0;
	}
}

MateriaSource::MateriaSource( const MateriaSource & src )
{

	for (int i = 0; i < 4; i++)
	{
		this->i_slot[i] = src.i_slot[i];
		this->slot[i] = src.slot[i];
	}
	this->idx = src.idx;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
// */

MateriaSource::~MateriaSource()
{
	
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

// MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

void MateriaSource::learnMateria(AMateria* src)
{
	int i;

	if (this->idx == 4)
		return ;
	for (i = 0; i < 4; i++)
	{
		if (this->i_slot[i] == 0)
		{
			this->i_slot[i] = 1;
			break;
		}
	}
	this->slot[i] = src;
	this->idx += 1;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->idx == 0)
		return (0);
	for (int i = 0; i <= this->idx; i++)
	{
		if (this->slot[i]->getType() == type)
			return (this->slot[i]->clone());
	}
	return (0);
	
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */