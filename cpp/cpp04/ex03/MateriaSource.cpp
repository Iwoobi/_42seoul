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

	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		this->i_slot[i] = src.i_slot[i];
		if (src.i_slot[i] == 1)
		{
			this->slot[i] = src.slot[i]->clone();
		}
		else
			this->slot[i] = NULL;
	}
	this->idx = src.idx;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
// */

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->i_slot[i] == 1)
			delete this->slot[i];
	}
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			this->i_slot[i] = rhs.i_slot[i];
			if (rhs.i_slot[i] == 1)
			{
				this->slot[i] = rhs.slot[i]->clone();
			}
			else
				this->slot[i] = NULL;
		}
		this->idx = rhs.idx;
	}
	return *this;
}

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
			this->slot[i] = src;
			this->idx += 1;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->idx == 0)
		return (0);
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i]->getType() == type)
		{
			return (this->slot[i]->clone());
		}
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