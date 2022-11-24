/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:09:52 by youhan            #+#    #+#             */
/*   Updated: 2022/11/24 22:44:15 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point tri_dot_1;
	Point tri_dot_2;
	Point point_dot;
	
	tri_dot_1 = a - b;
	tri_dot_2 = b - c;
	point_dot = c - a;
	if(tri_dot_1 * tri_dot_2 == 0|| tri_dot_2 * point_dot == 0 || point_dot * tri_dot_1  == 0)
	{
		std::cout << "check triangle Point ! " << std::endl;
		return (0);
	}
	tri_dot_1 = a - b;
	tri_dot_2 = a - c;
	point_dot = a - point;
	if (tri_dot_2 * point_dot != point_dot * tri_dot_1)
		return (0);
	tri_dot_1 = b - a;
	tri_dot_2 = b - c;
	point_dot = b - point;
	if (tri_dot_2 * point_dot != point_dot * tri_dot_1)
		return (0);
	tri_dot_1 = c - a;
	tri_dot_2 = c - b;
	point_dot = c - point;
	if (tri_dot_2 * point_dot != point_dot * tri_dot_1)
		return (0);
	return (1);
}