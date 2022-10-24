/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 18:55:04 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->myWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon newWeapon)
{
	this->myWeapon = &newWeapon;
}
