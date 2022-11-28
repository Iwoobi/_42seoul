#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap b("a");
	
	b.attack("asd");
	b.status();
	b.beRepaired(1);
	b.takeDamage(12);
	b.attack("asd");
}