/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:27:51 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/08 02:26:20 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point(void);
		Point(const float newX, const float newY);
		Point(const Point& newPoint);
		~Point(void);
		Point&	operator=(const Point& to_copy);
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif