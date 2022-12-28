#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	this->idx = 0;
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
		this->i_slot[i] = 0;
	}
}

Character::Character(std::string name)
{
	this->idx = 0;
	for (int i = 0; i < 4; i++)
		this->i_slot[i] = 0;
	this->name = name;
}
Character::Character( const Character & src )
{
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		this->i_slot[i] = src.i_slot[i];
		this->slot[i] = src.slot[i];
	}
	this->idx = src.idx;
}

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			this->i_slot[i] = rhs.i_slot[i];
			this->slot[i] = rhs.slot[i];
		}
		this->idx = rhs.idx;
	}
	return *this;
}
std::string const & Character::getName() const
{
	return (this->name);
}

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/



/*
** --------------------------------- METHODS ----------------------------------
*/

// std::string const & Character::getName() const
// {

// }

void Character::equip(AMateria* m)
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
	this->slot[i] = m;
	this->idx += 1;
}

void Character::unequip(int idx)
{
	if (this->idx < idx)
		return;
	this->slot[idx] = NULL;
	this->i_slot[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->i_slot[idx] == 0)
		return;
	this->slot[idx]->use(target);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */