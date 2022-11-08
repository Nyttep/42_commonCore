/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:26:33 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/08 02:26:58 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float newX, const float newY) : _x(newX), _y(newY)
{

}

Point::Point(const Point& newPoint) : _x(newPoint._x), _y(newPoint._y)
{
}

Point::~Point(void)
{
}

Point&	Point::operator=(const Point& to_copy)
{
	(void)to_copy;
	return(*this);
}

const Fixed	Point::getX(void) const
{
	return (this->_x);
}

const Fixed	Point::getY(void) const
{
	return (this->_y);
}
