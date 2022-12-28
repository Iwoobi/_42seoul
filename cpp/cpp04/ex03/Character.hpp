#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Character : public ICharacter
{

	public:

		Character();
		Character(std::string name);
		Character( Character const & src );
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character &				operator=( Character const & rhs );
	private:
		AMateria* slot[4];
		int i_slot[4];
		int idx;
		std::string name;
};


#endif /* ******************************************************* CHARACTER_H */