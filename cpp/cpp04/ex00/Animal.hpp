#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal(std::string src);
		Animal( Animal const & src );
		~Animal();

		Animal &	operator=( Animal const & rhs );
		void	makeSound() const;
		std::string	getType() const;
	protected:
		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */