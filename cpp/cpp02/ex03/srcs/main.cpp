/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:09 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/08 02:29:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main(void)
{
	const Point	a(0, 0);
	const Point	b(5, 0);
	const Point	c(0, 5);
	const Point	point(1, 1);
	bool	res;

	res = bsp(a, b, c, point);
	if (res)
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is not inside the triangle" << std::endl;
	return 0;
}