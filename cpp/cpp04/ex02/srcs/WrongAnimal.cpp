/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:35:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:01:32 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// --------------- Constructors & Destructors --------------
WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy) : _type(to_copy.getType())
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

// -------------- Operators overload --------------------
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& to_copy)
{
	this->_type = to_copy.getType();
	return (*this);
}

// ------------- Setters & Getters ---------------------
std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::setType(const std::string& newType)
{
	_type = newType;
}

// ------------ Other Functions -----------------
void	WrongAnimal::makeSound() const
{
}