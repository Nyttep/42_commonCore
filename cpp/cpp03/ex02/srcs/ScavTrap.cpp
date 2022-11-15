/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:45:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 17:01:28 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

//--------------- Constructors & Destructor ------------
ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName)
{
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
	std::cout << "ScavTrap String parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap()
{
	this->setHP(to_copy.getHP());
	this->setEP(to_copy.getEP());
	this->setAD(to_copy.getAD());
	this->setName(to_copy.getName());
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

//------------- Operators overload --------------------
ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	this->setHP(rhs.getHP());
	this->setEP(rhs.getEP());
	this->setAD(rhs.getAD());
	this->setName(rhs.getName());
	std::cout << "ScavTrap Copy operator called" << std::endl;
	return (*this);
}

//------------ Other Functions -----------------------

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEP() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " cannot attack because he has no Energy points left" << std::endl;
		return;
	}
	else if (this->getHP() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " cannot attack because he is dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAD() << " points of damage !" << std::endl;
	this->setEP(this->getEP() - 1);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " entered Gate Keeper mode !" << std::endl;
}
