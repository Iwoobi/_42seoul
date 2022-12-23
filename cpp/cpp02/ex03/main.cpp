/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:58 by youhan            #+#    #+#             */
/*   Updated: 2022/12/22 18:38:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
int main( void ) {
  Point a;
  Point b(2, 0);
  Point c(0, 2);
  Point d(1, 0.7);

  std::cout << bsp(a,b,c,d) << std::endl;

  return 0;
}