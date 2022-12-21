#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name)
{
	this->Name = name;
	this->hit_point = 100;
	this->attack_damage = 20;
	this->energy_point = 50;
	this->mode = 0;
	std::cout << "create ScavTrap " << this->Name <<std::endl;
}

ScavTrap:: ScavTrap()
{
	this->hit_point = 100;
	this->attack_damage = 20;
	this->energy_point = 50;
	this->mode = 0;
	std::cout << "create ScavTrap " <<std::endl;
}

ScavTrap:: ScavTrap( const  ScavTrap & src )
{
	this->hit_point = src.hit_point;
	this->attack_damage = src.attack_damage;
	this->energy_point = src.energy_point;
}

ScavTrap::~ ScavTrap()
{
	std::cout << "delete ScavTrap " << this->Name << std::endl;
}


ScavTrap &				 ScavTrap::operator=(  ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->Name = rhs.Name;
		this->hit_point = rhs.hit_point;
		this->attack_damage = rhs.attack_damage;
		this->energy_point = rhs.energy_point;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	if (this->mode == 0)
	{
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
		this->mode = 1;
	}
	else
	{
		std::cout << "ScavTrap is not now in Gate keeper mode" << std::endl;
		this->mode = 0;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_point == 0)
		{
			std::cout << "check energy point!" << std::endl;
			return ;
	}
	if (this->hit_point == 0)
	{
		std::cout << "ScavTrap " << this->Name <<  " is destroyed" << std::endl;
		return ;
	}
	this->energy_point -= 1;
	if (this->attack_damage == 0)
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", but miss !"<<std::endl;
	}
	else
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->attack_damage <<" points of damage!"<< std::endl;
}

int	ScavTrap::get_energy_point()
{
	return (this->ScavTrap::energy_point);
}
