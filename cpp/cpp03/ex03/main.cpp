#include "DiamondTrap.hpp"
int	main()
{
	DiamondTrap b("Q");
	b.status();
	b.attack("z");

	b.status();
	b.set_attack_dmg(20);
	b.status();
	b.attack("asd");
	b.status();
	b.beRepaired(1);
	b.status();
	b.takeDamage(12);
	b.status();
	b.attack("asd");
	b.status();
}