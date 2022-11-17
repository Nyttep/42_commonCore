/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:35:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:01:32 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// --------------- Constructors & Destructors --------------
Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& to_copy) : _type(to_copy.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

// -------------- Operators overload --------------------
Animal&	Animal::operator=(const Animal& to_copy)
{
	this->_type = to_copy.getType();
	return (*this);
}

// ------------- Setters & Getters ---------------------
std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::setType(const std::string& newType)
{
	_type = newType;
}

// ------------ Other Functions -----------------
void	Animal::makeSound() const
{
}