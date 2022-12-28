#include "AMateria.hpp"

AMateria::AMateria()
{
}


AMateria::AMateria(std::string const &type)
{
	this->type = type;
}
std::string const &AMateria::getType() const
{
	return (this->type);
}
AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
	std::cout << "not exist " << target.getName() << std::endl;
}