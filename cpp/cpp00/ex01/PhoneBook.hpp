/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:54:01 by youhan            #+#    #+#             */
/*   Updated: 2022/11/26 03:01:37 by youhan           ###   ########.fr       */
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
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenum;
		std::string	darkestsecret;
	};
	
	int	check_count();
	int	count;
	Node member[8];
	void	printf(int index);
	void	data_init();
	void	printf_char(std::string str);

	public:
	void	countprint();
	PhoneBook();
	void	add();
	void	search();
	void	exit();
};

#endif

