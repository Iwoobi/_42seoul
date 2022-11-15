/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:21:01 by youhan            #+#    #+#             */
/*   Updated: 2022/11/15 21:50:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name;
	std::cout << "attacks with his ";
	std::cout << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w) : weapon(w)
{
	this->name = name;
}

