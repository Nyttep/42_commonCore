/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:57:18 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 17:06:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// --------------- Constructors & Destructors -------------
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& to_copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = to_copy.getIdea(i);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

// ------------ Operators Overload -----------------------
Brain&	Brain::operator=(const Brain& to_copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = to_copy.getIdea(i);
	return (*this);
}

// ------------ Setters & Getters -----------------------
std::string	Brain::getIdea(int i) const
{
	return (_ideas[i]);
}

void	Brain::setIdea(std::string newIdea, int i)
{
	_ideas[i] = newIdea;
}
