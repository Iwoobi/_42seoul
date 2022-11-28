
#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>
void	PhoneBook::printf_char(std::string str)
{
	if (str.length() >= 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}
void	PhoneBook::countprint()
{
	std::cout << this->count << std::endl;
}

void	PhoneBook::printf(int index)
{
	std::cout << std::setw(10);
	std::cout << index + 1 << "|";
	printf_char(this->member[index].firstname);
	std::cout << "|";
	printf_char(this->member[index].lastname);
	std::cout << "|";
	printf_char(this->member[index].nickname);
	std::cout << std::endl;

}

void	PhoneBook::data_init()
{
	this->count = 0;
	for(int i = 0; i < 8; i++)
	{
		this->member[i].darkestsecret = "";
		this->member[i].nickname = "";
		this->member[i].lastname = "";
		this->member[i].phonenum = "";
		this->member[i].firstname = "";
	}
}

PhoneBook::PhoneBook()
{
	this->data_init();
}

int	PhoneBook::check_count()
{
	if (PhoneBook::count == 8)
		return (-1);
	return (1);
}

void	PhoneBook::add()
{
	if (this->check_count() == -1)
	{
		for(int i = 0; i < 7; i++)
		{
			this->member[i].firstname = this->member[i + 1].firstname;
			this->member[i].lastname = this->member[i + 1].lastname;
			this->member[i].nickname = this->member[i + 1].nickname;
			this->member[i].phonenum = this->member[i + 1].phonenum;
			this->member[i].darkestsecret = this->member[i + 1].darkestsecret;
		}
		this->count -= 1;
	}
	std::cout << "firstname" << std::endl;
	std::getline(std::cin,this->member[this->count].firstname);
	std::cout << "lastname" << std::endl;
	std::getline(std::cin, this->member[this->count].lastname);
	std::cout << "nickname" << std::endl;
	std::getline(std::cin, this->member[this->count].nickname);
	std::cout << "phonenum" << std::endl;
	std::getline(std::cin, this->member[this->count].phonenum);
	std::cout << "darkestsecret" << std::endl;
	std::getline(std::cin, this->member[this->count].darkestsecret);
	this->count += 1;
}

void	PhoneBook::search()
{
	int	index;
	std::stringstream	buf;
	std::string			num;
	if (this->count == 0)
	{
		std::cout << "Contact is blank" << std::endl;
		return ;
	}
	std::cout << "-----------------------------------------" <<  std::endl;
	std::cout << std::setw(11);
	std::cout << "index|";
	std::cout << std::setw(11);
	std::cout << "firstname|";
	std::cout << std::setw(11);
	std::cout << "lastname|";
	std::cout << std::setw(10);
	std::cout << "nickname" << std::endl;

	for(int i = 0; i < this->count; i++)
		this->printf(i);
	std::getline(std::cin, num);
	if (num.length() != 1)
	{
		std::cout << "---------------------------------------------" <<  std::endl;
		std::cout << "check index" << std::endl;
		std::cout << "---------------------------------------------" <<  std::endl;
		return ;
	}
	buf << num;
	buf >> index;
	if (index > this->count || index <= 0 )
	{
		std::cout << "---------------------------------------------" <<  std::endl;
		std::cout << "check index" << std::endl;
		std::cout << "---------------------------------------------" <<  std::endl;
		return ;
	}
	std::cout << "----------------------------------------------" <<  std::endl;
	std::cout << std::setw(16);
	std::cout << "firstname : ";
	std::cout << this->member[index - 1].firstname << std::endl;
	std::cout << std::setw(16);
	std::cout << "lastname : ";
	std::cout << this->member[index - 1].lastname << std::endl;
	std::cout << std::setw(16);
	std::cout << "nickname : ";
	std::cout << this->member[index - 1].nickname << std::endl;
	std::cout << std::setw(16);
	std::cout << "darkestsecret : ";
	std::cout << this->member[index - 1].darkestsecret << std::endl;
	std::cout << "----------------------------------------------" <<  std::endl;
}

void	PhoneBook::exit()
{
	this->data_init();
}
