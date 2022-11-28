#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->hit_point = 100;
	this->attack_damage = 30;
	this->energy_point = 100;
	std::cout << "create FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->Name = name;
	this->hit_point = 100;
	this->attack_damage = 30;
	this->energy_point = 100;
	std::cout << "create FragTrap " << this->Name <<std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	this->Name = src.Name;
	this->hit_point = src.hit_point;
	this->attack_damage = src.attack_damage;
	this->energy_point = src.energy_point;
}


FragTrap::~FragTrap()
{
	std::cout << "delete FragTrap " << this->Name << std::endl;
}



FragTrap &				FragTrap::operator=( FragTrap const & rhs )
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "high fives request" << std::endl;
}