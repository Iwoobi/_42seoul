
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
int zxc()
{

IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");

AMateria* tmp;

tmp = src->createMateria("ice");

me->equip(tmp);

tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
me->unequip(0);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
me->use(2, *bob);
me->use(3, *bob);
ICharacter* asd = new Character("asd");
*asd = *me;
delete me;
asd->use(0, *bob);
asd->use(1, *bob);
asd->use(2, *bob);
asd->use(3, *bob);
delete asd;
delete bob;
delete src;
return 0;
}

int main()
{
	zxc();
	// system("leaks ex03");
}