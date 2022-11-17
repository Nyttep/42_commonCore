/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:56:22 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 15:19:07 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//-------------------Constructors & Destructors ------------------------
AMateria::AMateria() : _type("")
{
	std::cout << "AMateria default Constructor Called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria string Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria& to_copy) : _type(to_copy.getType())
{
	std::cout << "AMateria copy Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria default Destructor Called" << std::endl;
}

//------------------ Operators Overload --------------------
AMateria&	AMateria::operator=(const AMateria& rhs)
{
	return (*this);
}

//------------------ Setters & Getters ---------------------
const std::string&	AMateria::getType() const
{
	return (_type);
}

//----------------- Others Functions -----------------------
void	AMateria::use(ICharacter& target)
{
	
}
