/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/27 17:16:36 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	this->name = newName;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->myWeapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon newWeapon)
{
	this->myWeapon = &newWeapon;
	return ;
}
