/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:10:20 by youhan            #+#    #+#             */
/*   Updated: 2022/11/15 21:16:07 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string	Weapon::getType()
{
	return (this->type);
}

Weapon::Weapon(std::string	type)
{
	this->type = type;
}

Weapon::Weapon(){}


void		Weapon::setType(std::string type)
{
	this->type = type;
}