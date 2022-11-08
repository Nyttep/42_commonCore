/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:02:57 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/07 23:10:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int	_binary_point;
	public:
		Fixed(void);
		Fixed(const Fixed& to_copy);
		Fixed(const int new_copy);
		Fixed(const float new_copy);
		~Fixed(void);
		Fixed&	operator=(const Fixed& to_copy);
		bool	operator==(const Fixed& to_compare) const;
		bool	operator<(const Fixed& to_compare) const;
		bool	operator>(const Fixed& to_compare) const;
		bool	operator<=(const Fixed& to_compare) const;
		bool	operator>=(const Fixed& to_compare) const;
		bool	operator!=(const Fixed& to_compare) const;
		Fixed	operator+(const Fixed& to_add) const;
		Fixed	operator-(const Fixed& to_sub) const;
		Fixed	operator*(const Fixed& to_mult) const;
		Fixed	operator/(const Fixed& to_div) const;
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& o, const Fixed& to_display);

#endif