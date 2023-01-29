#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource(const MateriaSource & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );
	
		void learnMateria(AMateria* src);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria* slot[4];
		int i_slot[4];
		int idx;
		std::string name;

};


#endif /* *************************************************** MATERIASOURCE_H */