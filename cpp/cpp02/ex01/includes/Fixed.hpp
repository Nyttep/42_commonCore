/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:02:57 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/31 16:14:25 by pdubois          ###   ########.fr       */
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
		std::ostream&	operator<<(std::ostream& o, const Fixed& to_copy);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

#endif