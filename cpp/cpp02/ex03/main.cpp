/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:58 by youhan            #+#    #+#             */
/*   Updated: 2022/11/24 22:43:05 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
int main( void ) {
  Point a;
  Point b(-1, 0);
  Point c(0, 2);
  Point d(1, 1);

  std::cout << bsp(a,b,c,d) << std::endl;

  system("leaks ex03");
  return 0;
}