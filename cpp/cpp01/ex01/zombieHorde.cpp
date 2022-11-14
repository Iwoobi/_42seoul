/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:07:09 by youhan            #+#    #+#             */
/*   Updated: 2022/11/14 21:27:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>
Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zom = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		std::stringstream	num;
		std::string			temp;
		num << i + 1;
		num >> temp;
		zom[i].init_info(name + temp);
	}
	return (zom);
}