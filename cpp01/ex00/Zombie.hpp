/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:13:47 by youhan            #+#    #+#             */
/*   Updated: 2022/11/04 18:49:18 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
	std::string	name;
	public:
	~Zombie();
	Zombie(std::string name);
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

