/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:43 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:03:55 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

// --------------- Constructors & Destructors --------------
Dog::Dog()
{
	setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& to_copy) : Animal()
{
	setType(to_copy.getType());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

// -------------- Operators overload --------------------
Dog&	Dog::operator=(const Dog& to_copy)
{
	this->_type = to_copy.getType();
	return (*this);
}

// ------------- Other Functions -------------------------
void	Dog::makeSound() const
{
	std::cout << "Bark Bark Bark" << std::endl;
}