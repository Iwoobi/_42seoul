#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


DiamondTrap::DiamondTrap(std::string name)
{
	ScavTrap	scav;
	FragTrap	frag;
	this->Name = name;
	this->ClapTrap::Name = name + "_clap_name";
	this->hit_point = frag.get_hit_point();
	this->attack_damage = frag.get_attack_damage();
	this->energy_point = scav.get_energy_point();
	std::cout << "create DiamondTrap " << this->Name <<std::endl;
}

DiamondTrap::DiamondTrap()
{
	ScavTrap	scav;
	FragTrap	frag;

	this->Name = "";
	this->ClapTrap::Name = this->Name + "_clap_name";
	this->hit_point = frag.get_hit_point();
	this->attack_damage = frag.get_attack_damage();
	this->energy_point = scav.get_energy_point();
	std::cout << "create DiamondTrap" <<std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	this->Name = src.Name;
	this->hit_point = src.hit_point;
	this->attack_damage = src.attack_damage;
	this->energy_point = src.energy_point;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "delete DiamondTrap " << this->Name << std::endl;

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
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

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}