/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:30:52 by youhan            #+#    #+#             */
/*   Updated: 2022/11/14 21:31:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *e;

	e = zombieHorde(11, "e");
	for (int i = 0; i < 11; i++)
		e[i].announce();
	delete[] e;
	system("leaks Zombie");
}