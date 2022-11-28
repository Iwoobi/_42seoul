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
		std::getline(std::cin, input);
		if (input == "SEARCH")
			data.search();
		else if (input == "ADD")
			data.add();
		else if (input == "EXIT")
		{
			data.exit();
			break;
		}
	}
	system("leaks ex01");
	return (1);
}