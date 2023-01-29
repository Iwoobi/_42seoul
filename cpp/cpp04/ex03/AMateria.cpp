#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "";
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

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	this->type = rhs.getType();
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "not exist " << target.getName() << std::endl;
}