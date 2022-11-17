/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:03:35 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

// --------------- Constructors & Destructors --------------
Cat::Cat()
{
	setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& to_copy) : Animal()
{
	setType(to_copy.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

// -------------- Operators overload --------------------
Cat&	Cat::operator=(const Cat& to_copy)
{
	this->_type = to_copy.getType();
	return (*this);
}

// ------------- Other Functions ----------------------
void	Cat::makeSound() const
{
	std::cout << "Meeeeoooowwww" << std::endl;
}