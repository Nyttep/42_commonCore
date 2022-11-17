/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:17:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// --------------- Constructors & Destructors --------------
WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& to_copy) : WrongAnimal()
{
	setType(to_copy.getType());
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

// -------------- Operators overload --------------------
WrongCat&	WrongCat::operator=(const WrongCat& to_copy)
{
	this->_type = to_copy.getType();
	return (*this);
}

// ------------- Other Functions ----------------------
void	WrongCat::makeSound() const
{
	std::cout << "Meeeeoooowwww" << std::endl;
}