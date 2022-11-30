/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:38:17 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 14:48:32 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Converter
{
	private :
		static const std::string	_types[10];
		std::string	_trueType;
	public :
		Converter();
		Converter(std::string newTrueType);
		Converter(const Converter& toCopy);
		~Converter();
		Converter&	operator=(const Converter& toCopy);
		std::string	getType() const;
		void	setType(std::string newType);
		std::string	findType(std::string newtype) const;
};

#endif