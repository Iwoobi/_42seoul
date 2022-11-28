#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("M1");
	
	a.set_attack_dmg(2);
	a.attack("asd");
	a.status();
	a.beRepaired(1);
	a.takeDamage(12);
	a.attack("asd");
}