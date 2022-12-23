/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:58 by youhan            #+#    #+#             */
/*   Updated: 2022/12/22 18:25:46 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
  Fixed a(2);
  Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << a / b << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << "----------------------1" << std::endl;
  std::cout << a++ << std::endl;
  std::cout << "----------------------1" << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  std::cout << Fixed::min( a, b ) << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << Fixed::min( a, 10 ) << std::endl;
  std::cout << Fixed::max( a, 10 ) << std::endl;
  return 0;
}
 