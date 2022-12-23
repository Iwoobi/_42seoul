#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:
		virtual	~Animal();

		Animal &	operator=( Animal const & rhs );
		virtual	void	makeSound() const = 0;
		std::string	getType() const;
		Animal();
		Animal(std::string src);
		Animal( Animal const & src );
		
	protected:
		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */