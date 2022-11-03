/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:02:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/03 18:14:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = to_copy.getRawBits();
}

Fixed::Fixed(const int new_copy)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = new_copy  * 256; // correspond to a bitsift of 8 to the left, but doing it the bitshifting way always rounds downs
}

Fixed::Fixed(const float new_copy)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(new_copy  * 256); // correspond to a bitsift of 8 to the left, but doing it the bitshifting way always rounds downs
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
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

Fixed	operator+(const Fixed& to_add) const
{
	return (this->_value + to_add._value);
}

Fixed	operator-(const Fixed& to_sub) const
{
	return (this->_value - to_add._value);
}

Fixed	operator*(const Fixed& to_mult) const
{
	return (this->_value + to_add._value); // CXHANGE
}

Fixed	operator/(const Fixed& to_div) const
{
	return (this->_value + to_add._value); //CHANMGE
}

Fixed	operator+(const Fixed& to_add)const
{
	return (this->_value + to_add._value);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& to_copy)
{
	o << to_copy.toFloat();
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
	return (ret / 256);
}

int	Fixed::toInt(void) const
{
	return (this->_value / 256);
}

const int	Fixed::_binary_point = 8;
