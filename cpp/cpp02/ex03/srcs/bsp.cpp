/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:54:54 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/08 02:28:05 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Fixed getVector1(const Point a, const Point b, const Point c, const Point p)
{
	Fixed	vector1;

	vector1 = Fixed(((a.getX() * (c.getY() * a.getY())) + ((p.getY() - a.getY()) * (c.getX() - a.getX())) - (p.getX() * (c.getY() - a.getY()))) / (((b.getY() - a.getY()) * (c.getX() - a.getX())) - ((b.getX() - a.getX()) * (c.getY() - a.getY()))));
	return (vector1); 
}

const Fixed getVector2(const Point a, const Point b, const Point c, const Point p, const Fixed vector1)
{
	Fixed	vector2;

	vector2 = Fixed((p.getY() - a.getY() - (vector1 * (b.getY() - a.getY()))) / (c.getY() - a.getY()));
	return (vector2);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	vector1(getVector1(a, b, c, point));
	Fixed	vector2(getVector2(a, b, c, point, vector1));

	if (vector1 > 0 && vector2 > 0 && (vector1 + vector2) < 1)
		return (1);
	else
		return (0);
}
