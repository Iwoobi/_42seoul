#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int test()
{
	Animal *i = new Cat();
	Animal *j = new Dog();

	delete i;
	delete j;

	Animal *k[50];
	Animal *l[50];
	for(int i = 0; i<5; i++)
	{
		k[i] = new Cat();
		l[i] = new Dog();
	}
	for (int i = 0; i < 5; i++)
	{
		delete k[i];
		delete l[i];
	}
	Animal *ani[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			ani[i] = new Cat();
		else
			ani[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete ani[i];
	std::cout << "----------------" << std::endl;
	Cat a;
	Cat b;
	Cat c;
	Cat d = c;
	a = b;
	
	std::cout << "----------------" << std::endl;

	return 0;

}

int main()
{
	test();
		system("leaks ex01");
	return 0;
}

