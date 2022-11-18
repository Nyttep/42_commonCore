/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:52:40 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/18 18:07:34 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//-------------------Constructors & Destructors ------------------------
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default Constructor Called" << std::endl;
}

Cure::Cure(const Cure& to_copy) : AMateria(to_copy.getType())
{
	std::cout << "Cure copy Constructor Called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure default Destructor Called" << std::endl;
}

//------------------ Operators Overload --------------------
Cure&	Cure::operator=(const Cure& rhs)
{
	(void)rhs;
	return (*this);
}

//----------------- Others Functions -----------------------
AMateria*	Cure::clone() const
{
	AMateria*	ret;
	ret = new Cure;
	return (ret);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
