/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:06:38 by youhan            #+#    #+#             */
/*   Updated: 2022/11/26 04:02:42 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[debug]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[info]\n" << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[warning]\n" << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[error]\n" << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*f[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string		f1[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;
	for (i = 0; i < 4; i++)
	{
		if (f1[i] == level)
			break;
	}
	if (i == 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	for (;i < 4; i++)
		(this->*f[i])();
	// switch (i)
	// {
	// 	case 0:
	// 		(this->*f[0])();
	// 	case 1:
	// 		(this->*f[1])();
	// 	case 2:
	// 		(this->*f[2])();
	// 	case 3:
	// 		(this->*f[3])();
	// 	break;
	// 	default:
	// 		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	// 	break;

		
	// }
}