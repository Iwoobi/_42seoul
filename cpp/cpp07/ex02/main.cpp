
#include "Array.hpp"

int main(void)
{
	Array<std::string> a(3);
	Array<std::string> b(3);
	a[0] = "asd";
	a[1] = "qwe";
	a[2] = "zxc";
	for (std::size_t i = 0 ; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	b = a;
	for (std::size_t i = 0 ; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	try
	{
	a[3] = "error";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

