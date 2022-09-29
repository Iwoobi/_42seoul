/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:54:01 by youhan            #+#    #+#             */
/*   Updated: 2022/09/30 02:59:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>

class PhoneBook
{
	private:
	class Node
	{
		public:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNum;
		std::string	DarkestSecret;
		Node	*next;
	};
	
	int	check_count();
	int	count;
	Node* Head;

	public:
	PhoneBook();
	void	countprint();
	void	printf(int index, Node data);
	void	add();
	void	search();
	void	exit();
};

void	PhoneBook::countprint()
{
	std::cout << PhoneBook::count << std::endl;
}

void	PhoneBook::printf(int index, Node data)
{
	std::cout << index << std::endl;
	std::cout << data.FirstName << std::endl;
	std::cout << data.LastName << std::endl;
	std::cout << data.NickName << std::endl;
}

PhoneBook::PhoneBook()
{
	Head = NULL;
	PhoneBook::count = 0;
}

int	PhoneBook::check_count()
{
	if (PhoneBook::count >= 8)
		return (-1);
	return (1);
}

void	PhoneBook::add()
{
	if (PhoneBook::check_count() == -1)
	{
		Node *temp = Head;
		Head = Head->next;
		delete temp;
		PhoneBook::count -= 1;
		PhoneBook::add();
		return ;
	}
	else
	{
		Node* NewNode = new Node;
		
		std::cout << "FirstName" << std::endl;
		std::cin >> NewNode->FirstName;
		std::cout << "lastName" << std::endl;
		std::cin >> NewNode->LastName;
		std::cout << "NickName" << std::endl;
		std::cin >> NewNode->NickName;
		std::cout << "PhoneNum" << std::endl;
		std::cin >> NewNode->PhoneNum;
		std::cout << "DarkestSecret" << std::endl;
		std::cin >> NewNode->DarkestSecret;
		NewNode->next = NULL;
		if (Head == NULL)
			Head = NewNode;
		else if (Head->next == NULL)
			Head->next = NewNode;
		else
		{
			Node* temp = Head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = NewNode;
		}
		PhoneBook::count += 1;
	}
}

void	PhoneBook::search()
{
	Node	*temp = Head;
	int		index = 1;
	if (temp == NULL)
	{
		std::cout << "Contact is blank" << std::endl;
		return ;
	}
	while (temp != NULL)
	{
		PhoneBook::printf(index, *temp);
		index += 1;
		temp = temp->next;
	}
}

void	PhoneBook::exit()
{
	Node	*temp = Head;
	Node	*temp1;

	if (temp == NULL)
		return ;
	while (temp->next != NULL)
	{
		temp1 = temp->next;
		delete temp;
		temp = temp1;
	}
	delete temp;
}

#endif

