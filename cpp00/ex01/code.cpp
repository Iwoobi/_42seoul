#include "PhoneBook.hpp"

int	main()
{
	std::string input;
	PhoneBook	data;


	while (1)
	{
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