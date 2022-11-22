/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:06:41 by youhan            #+#    #+#             */
/*   Updated: 2022/11/22 19:40:15 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
#include <iostream>

class Harl
{
	private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public:

	void complain( std::string level );
};

#endif