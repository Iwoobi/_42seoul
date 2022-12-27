#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal *l = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	Animal* a1;

	a1 = NULL;
	std::cout << "\n\n\n"<< std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << "-----------------------------------"<< std::endl;
	
	std::cout << "\n\n\n"<< std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "-----------------------------------"<< std::endl;
	l->makeSound();
	k->makeSound();
	std::cout << "-----------------------------------"<< std::endl;
	std::cout << "\n\n\n"<< std::endl;


	delete j;
	delete i;
	delete meta;
	std::cout << "-----------------------------------"<< std::endl;
	delete l;
	delete k;
	std::cout << "-----------------------------------"<< std::endl;
	
	return 0;
}
