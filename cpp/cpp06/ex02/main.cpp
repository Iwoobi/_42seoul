
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <stdlib.h>
#include <time.h>
Base * generate(void)
{
	Base *tmp;
	if (rand() % 3 == 0)
	{
		tmp = new A;
		std::cout << "create A" << std::endl;
	}
	else if (rand() % 3 == 1)
	{
		tmp = new B;
		std::cout << "create B" << std::endl;
	}
	else
	{
		tmp = new C;
		std::cout << "create C" << std::endl;
	}
	return (tmp);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}
void identify(Base& p)
{
	Base tmp_a;
	Base tmp_b;
	Base tmp_c;
	try
	{
		tmp_a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		tmp_b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		tmp_c =dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	std::cout << "no A,B,C, check!" << std::endl;
	
}
int	main()
{
		srand(time(NULL));
	Base *a1 = generate();
	Base *a2 = generate();
	Base *a3 = generate();
	Base b;
	identify(a1);
	identify(a2);
	identify(a3);


	identify(*a1);
	identify(*a2);
	identify(*a3);
	identify(b);
	delete a1;
	delete a2;
	delete a3;


}