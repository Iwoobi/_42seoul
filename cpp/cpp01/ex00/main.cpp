/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:51:56 by youhan            #+#    #+#             */
/*   Updated: 2022/11/04 18:55:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	Zom = Zombie("asd");
	Zom.announce();
	Zombie	*Zom1 = new Zombie("qwe");
	Zom1->announce();
	Zombie	*Zom2 = newZombie("zxc");
	Zom2->announce();
	randomChump("123");
	delete Zom1;
	delete Zom2;
	
}