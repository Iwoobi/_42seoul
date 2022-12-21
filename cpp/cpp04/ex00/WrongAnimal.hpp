#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal(std::string src);
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &	operator=( WrongAnimal const & rhs );
		void	makeSound() const;
		std::string	getType() const;
	protected:
		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */