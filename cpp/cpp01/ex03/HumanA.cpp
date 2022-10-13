/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:47 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/27 17:12:07 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string myName, Weapon newWeapon)
{
	this->name = myName;
	this->myWeapon = newWeapon;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->myWeapon.getType() << std::endl;
	return ;
}
