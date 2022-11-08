/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:02:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/07 23:10:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const Fixed& new_copy)
{
	this->_value = new_copy.getRawBits();
}

Fixed::Fixed(const int new_copy)
{
	this->_value = new_copy  * (1 << 8); // correspond to a bitsift of 8 to the left, but doing it the bitshifting way always rounds downs
}

Fixed::Fixed(const float new_copy)
{
	this->_value = roundf(new_copy  * (1 << 8)); // correspond to a bitsift of 8 to the left, but doing it the bitshifting way always rounds downs
}

Fixed::~Fixed(void)
{
}

Fixed&	Fixed::operator=(const Fixed& to_copy)
{
	this->_value = to_copy.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed& to_compare) const
{
	return (_value == to_compare._value);
}

bool	Fixed::operator<(const Fixed& to_compare) const
{
	return (_value < to_compare._value);
}

bool	Fixed::operator>(const Fixed& to_compare) const
{
	return !(*this < to_compare || *this == to_compare);
}

bool	Fixed::operator<=(const Fixed& to_compare) const
{
	return (*this < to_compare || *this == to_compare);
}

bool	Fixed::operator>=(const Fixed& to_compare) const
{
	return !(*this < to_compare);
}

bool	Fixed::operator!=(const Fixed& to_compare) const
{
	return !(*this == to_compare);
}

Fixed	Fixed::operator+(const Fixed& to_add) const
{
	Fixed	ret;

	ret._value = this->_value + to_add._value;
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& to_sub) const
{
	Fixed	ret;

	ret._value = this->_value - to_sub._value;
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& to_mult) const
{
	Fixed	ret;

	ret._value = ((long int)this->_value * (long int)to_mult._value) / (1 << 8);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& denom) const
{
	Fixed	ret;

	ret._value = ((long int)this->_value * (1 << 8)) / denom._value;
	return (ret);
}

Fixed	Fixed::operator++(void)
{
	Fixed	ret;

	ret._value = ++(this->_value);
	return (ret);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret;

	ret._value = (this->_value)++;
	return (ret);
}

Fixed	Fixed::operator--(void)
{
	Fixed	ret;

	ret._value = --(this->_value);
	return (ret);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret;

	ret._value = (this->_value)--;
	return (ret);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& to_display)
{
	o << to_display.toFloat();
	return (o);
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	ret = this->_value;
	return (ret / (1 << 8));	//correspond to a bitshift of 8 to the right
}

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << 8));	//correspond to a bitshift of 8 to the right
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const int	Fixed::_binary_point = 8;
