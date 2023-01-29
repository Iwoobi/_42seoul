#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
class ICharacter;

class AMateria
{

	public:

		AMateria();

		AMateria(std::string const &type);
		virtual ~AMateria();

		std::string const & getType() const;
		AMateria &				operator=( AMateria const & rhs );
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string type;

};

#endif /* ******************************************************** AMATERIA_H */