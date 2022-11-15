/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:50 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 17:17:35 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//--------------- Constructors & Destructors --------------
ClapTrap::ClapTrap(void) : _Name("not named"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string newName) : _Name(newName), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap String parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy) : _Name(to_copy.getName()), _HitPoints(to_copy.getHP()), _EnergyPoints(to_copy.getEP()), _AttackDamage(to_copy.getAD())
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

//---------------- Getters & Setters -------------------
int	ClapTrap::getHP(void) const
{
	return (this->_HitPoints);
}

void	ClapTrap::setHP(int	newHP)
{
	this->_HitPoints = newHP;
}

int	ClapTrap::getEP(void) const
{
	return (this->_EnergyPoints);
}

void	ClapTrap::setEP(int	newEP)
{
	this->_EnergyPoints = newEP;
}

int	ClapTrap::getAD(void) const
{
	return (this->_AttackDamage);
}

void	ClapTrap::setAD(int	newAD)
{
	this->_AttackDamage = newAD;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_Name);
}

void	ClapTrap::setName(const std::string newName)
{
	this->_Name = newName;
}

//----------- Operators overload -----------------
ClapTrap&	ClapTrap::operator=(const ClapTrap& to_copy)
{
	this->_HitPoints = to_copy.getHP();
	this->_EnergyPoints = to_copy.getEP();
	this->_AttackDamage = to_copy.getAD();
	this->_Name = to_copy.getName();
	std::cout << "ClapTrap Copy operator called" << std::endl;
	return(*this);
}

//------------- Other Functions -------------------
void	ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot attack because he has no Energy points left" << std::endl;
		return;
	}
	else if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot attack because he is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
	this->_EnergyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot be repaired because he has no Energy points left" << std::endl;
		return;
	}
	else if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot be repaired because he is dead" << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->_Name << " repairs himself regaining " << amount << " Hit points !" << std::endl;
	this->_HitPoints += amount;
	this->_EnergyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 1)
		std::cout << "ClapTrap " << this->_Name << " takes " << amount << " damages !" << std::endl;
	else
		std::cout << "ClapTrap " << this->_Name << " takes " << amount << " damage !" << std::endl;
	this->_HitPoints -= amount;
}
