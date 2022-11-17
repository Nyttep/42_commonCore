/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:43 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 19:02:48 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

// --------------- Constructors & Destructors --------------
Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	_myBrain = new Brain();
}

Dog::Dog(const Dog& to_copy) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	setType(to_copy.getType());
	_myBrain = to_copy.getBrain();
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
	delete _myBrain;
}

// -------------- Operators overload --------------------
Dog&	Dog::operator=(const Dog& to_copy)
{
	this->_type = to_copy.getType();
	this->_myBrain = to_copy.getBrain();
	return (*this);
}

//-------------- Setters & Getters --------------------
Brain*	Dog::getBrain() const
{
	return (_myBrain);
}

void	Dog::setBrain(Brain* newBrain)
{
	delete _myBrain;
	_myBrain = newBrain;
}

// ------------- Other Functions -------------------------
void	Dog::makeSound() const
{
	std::cout << "Bark Bark Bark" << std::endl;
}