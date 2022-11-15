/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:35:21 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 18:27:25 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//--------------- Constructors & Destructor ------------
DiamondTrap::DiamondTrap(void) : _Name("not named")
{
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	ClapTrap::_Name = _Name + "_clap_name";
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& newName) : _Name(newName)
{
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	ClapTrap::_Name = _Name + "_clap_name";
	std::cout << "DiamondTrap String parameter constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& to_copy) : ClapTrap(), ScavTrap(), FragTrap(), _Name(to_copy._Name)
{
	this->_HitPoints = to_copy.getHP();
	this->_EnergyPoints = to_copy.getEP();
	this->_AttackDamage = to_copy.getAD();
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

//------------- Operators overload --------------------
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	this->setHP(rhs.getHP());
	this->setEP(rhs.getEP());
	this->setAD(rhs.getAD());
	this->_Name = rhs._Name;
	this->ClapTrap::_Name = rhs.ClapTrap::_Name;
	std::cout << "DiamondTrap Copy operator called" << std::endl;
	return (*this);
}

//------------ Other Functions -----------------------
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "My name is " << _Name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_Name << std::endl;
}
