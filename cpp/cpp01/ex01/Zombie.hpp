/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:57:45 by youhan            #+#    #+#             */
/*   Updated: 2022/11/14 17:39:14 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
	std::string	name;
	public:
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void	announce(void);
	void	init_info(std::string name);
};

Zombie* zombieHorde(int N, std::string name);