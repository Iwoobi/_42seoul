#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	this->attack_damage = 0;
	this->hit_point = 10;
	this->energy_point = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->attack_damage = 0;
	this->hit_point = 10;
	this->energy_point = 10;
	std::cout << "create ClapTrap " << this->Name << std::endl;
}


ClapTrap::ClapTrap( const ClapTrap & src )
{
	this->attack_damage = src.attack_damage;
	this->Name = src.Name;
	this->hit_point = src.hit_point;
	this->energy_point = src.energy_point;
	std::cout << "copy ClapTrap " << this->Name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "delete ClapTrap" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->attack_damage = rhs.attack_damage;
		this->Name = rhs.Name;
		this->hit_point = rhs.hit_point;
		this->energy_point = rhs.energy_point;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }

void ClapTrap::status()
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "ClapTrap " << this->Name << " hit_point : " << this->hit_point << std::endl;
	std::cout << "ClapTrap " << this->Name << " energy_point : " << this->energy_point << std::endl;
	std::cout << "ClapTrap " << this->Name << " attack_damage : " << this->attack_damage << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_point == 0)
	{
		std::cout << "check energy point!" << std::endl;
		return ;
	}
	if (this->hit_point == 0)
	{
		std::cout << "ClapTrap " << this->Name <<  " is destroyed" << std::endl;
		return ;
	}
	this->energy_point -= 1;
	if (this->attack_damage == 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", but miss !"<<std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->attack_damage <<" points of damage!"<< std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_point -= amount;
	std::cout << "ClapTrap " << this->Name << " is attackd, " << amount <<" points of damage!"<< std::endl;
	if (this-> hit_point <= 0)
	{
		this->hit_point = 0;
		std::cout << "ClapTrap " << this->Name <<  " is destroyed" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point == 0)
	{
		std::cout << "check energy point!" << std::endl;
		return ;
	}
	if (this->hit_point == 0)
	{
		std::cout << "ClapTrap " << this->Name <<  " is destroyed" << std::endl;
		return ;
	}
	this->energy_point -= 1;
	this->hit_point += amount;
	std::cout << "ClapTrap " << this->Name << " is repaired.  " << "hit_point : " << this->hit_point-1 << " -> " << this->hit_point << std::endl;
}

void ClapTrap::set_attack_dmg(int dmg)
{
	this->attack_damage = dmg;
}