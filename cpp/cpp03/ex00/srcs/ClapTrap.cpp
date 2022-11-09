/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:50 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/09 02:41:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("not named"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string newName) : _Name(newName), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "String parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap to_copy) : _Name(to_copy._Name), _HitPoints(to_copy._HitPoints), _EnergyPoints(to_copy._EnergyPoints), _AttackDamage(to_copy._AttackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap&	operator=(const ClapTrap& to_copy)
{
	this->_HitPoints = to_copy._HitPoints;
	this->_EnergyPoints = to_copy._EnergyPoints;
	this->_AttackDamage = to_copy._AttackDamage;
	std::cout << "Copy operator called" << std::endl;
	return(*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot attack because he has no Energy points" << std::endl;
		return();
	}
	else if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_Name << " cannot attack because he's dead" << std::endl;
		return();
	}
	
	this->_HitPoints--;
}
