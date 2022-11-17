/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:50 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 16:51:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//-------------------Constructors & Destructors ------------------------
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default Constructor Called" << std::endl;
}

Ice::Ice(const Ice& to_copy) : AMateria("ice")
{
	std::cout << "Ice copy Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice default Destructor Called" << std::endl;
}

//------------------ Operators Overload --------------------
Ice&	Ice::operator=(const Ice& rhs)
{
	return (*this);
}

//----------------- Others Functions -----------------------
AMateria*	Ice::clone() const
{
	AMateria*	ret;
	ret = new Ice;
	return (ret);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
