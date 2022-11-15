/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:40 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 17:15:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

//--------------- Constructors & Destructor ------------
FragTrap::FragTrap(void) : ClapTrap()
{
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName)
{
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
	std::cout << "FragTrap String parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap()
{
	this->setHP(to_copy.getHP());
	this->setEP(to_copy.getEP());
	this->setAD(to_copy.getAD());
	this->setName(to_copy.getName());
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

//------------- Operators overload --------------------
FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	this->setHP(rhs.getHP());
	this->setEP(rhs.getEP());
	this->setAD(rhs.getAD());
	this->setName(rhs.getName());
	std::cout << "FragTrap Copy operator called" << std::endl;
	return (*this);
}

//------------ Other Functions -----------------------

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " asks for a high five !" << std::endl;
}
