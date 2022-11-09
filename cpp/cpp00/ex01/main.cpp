#include "PhoneBook.hpp"

void	printf_data()
{
	std::cout << "ADD : save a new contact" << std::endl;
	std::cout << "SEARCH : display a specific contact" << std::endl;
	std::cout << "EXIT : exit" << std::endl;
}

int	main()
{
	std::string input;
	PhoneBook	data;

	while (1)
	{
		printf_data();
		std::cin >> input;
		if (input == "SEARCH")
			data.search();
		else if (input == "ADD")
			data.add();
		else if (input == "EXIT")
		{
			data.exit();
			break;
		}
		else if (input == "count")
		{
			data.countprint();
		}
	}
	system("leaks my_phone");
	return (1);
}