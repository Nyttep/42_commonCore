/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:48:18 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:11:20 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"
//------------------------ Static Variables -------------------------
const std::string	Converter::_types[10] = {"char", "int", "float", "double", "-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

//------------------- Constructors & Destructors --------------------
Converter::Converter()
{
	std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(std::string newTrueType)
{
	_trueType = findType(newTrueType);
	std::cout << "Converter args constructor called" << std::endl;
}

Converter::Converter(const Converter& toCopy)
{
	*this = toCopy;
	std::cout << "Converter copy constructor called" << std::endl;
}

Converter::~Converter()
{
	std::cout << "Converter default destructor called" << std::endl;
}

//----------------------- Operators overloads ------------------------
Converter&	Converter::operator=(const Converter& toCopy)
{
	this->_trueType = toCopy.getType();
	return (*this);
}

//----------------------- Setters & Getters --------------------------
std::string	Converter::getType() const
{
	return (_trueType);
}

void	Converter::setType(std::string newType)
{
	for (int i = 0; i <= 9; i++)
	{
		if (newType == _types[i])
		{
			_trueType = newType;
			return ;
		}
	}
	std::cerr << "the new type is invalid\n";
}

//------------------------ Other Functions ---------------------------
std::string	Converter::findType(std::string newType) const
{
	bool	dec = 0;

	for (int i = 4; i <= 9; i++)
	{
		if (newType == _types[i])
			return (newType);
	}
	if (newType.length() == 1)
	{
		if (std::isdigit(newType[0]))
			return ("int");
		if (std::isprint(newType[0]) && !std::isdigit(newType[0]))
			return ("char");
	}
	for (int i = 0; newType[i]; i++)
	{
		if (newType[i] == '.')
			dec = 1;
	}
	if (newType[newType.length() - 1] == 'f')
		return ("float");
	if (dec == 0)
		return ("int");
	else
		return ("double");

	return ("");
}
