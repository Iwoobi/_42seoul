#include "DiamondTrap.hpp"
int	main()
{
	DiamondTrap b("asd");
	b.status();
	b.attack("z");

	
	b.attack("asd");
	b.beRepaired(1);
	b.takeDamage(12);
	b.attack("asd");
}