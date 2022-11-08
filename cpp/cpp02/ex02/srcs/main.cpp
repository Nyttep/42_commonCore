/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:09 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/07 23:45:34 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	 
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	a = Fixed(2);
	std::cout << b + a << std::endl;
	std::cout << b - a << std::endl;
	std::cout << b / 0 << std::endl;
	std::cout << b * a << std::endl;

	if (b > 1)
		std::cout << "Operator > works" << std::endl;
	if (b > 12)
		std::cout << "Operator > doesnt works" << std::endl;
	if (b < 12)
		std::cout << "Operator < works" << std::endl;
	if (b < 1)
		std::cout << "Operator < doesnt works" << std::endl;
	if (a == 2)
		std::cout << "Operator == works" << std::endl;
	if (a == 3)
		std::cout << "Operator == doesnt works" << std::endl;
	if (a != 3)
		std::cout << "Operator != works" << std::endl;
	if (a != 2)
		std::cout << "Operator != doesnt works" << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	return 0;
}