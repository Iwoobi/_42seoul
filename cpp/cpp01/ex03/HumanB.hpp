/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:12:18 by youhan            #+#    #+#             */
/*   Updated: 2022/11/15 21:45:17 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class	HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;
	public:
	HumanB(std::string name);
	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif