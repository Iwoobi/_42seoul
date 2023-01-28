
#include <iostream>

struct Data
{
	int a;
};
uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
int	main()
{
	Data	a;
	std::cout << "orign ptr : " << &a << std::endl;
	uintptr_t b = serialize(&a);
	std::cout << "uintptr_t : " <<  b << std::endl;
	std::cout << "Data * : " <<  deserialize(b) << std::endl;
}