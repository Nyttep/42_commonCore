/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 18:34:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Player1("Player1");
	DiamondTrap	guest;
	DiamondTrap	Player2(Player1);
	
	Player1.attack(guest.getName());
	guest.takeDamage(Player1.getAD());
	guest.beRepaired(Player2.getAD());
	Player2.guardGate();
	Player2.highFivesGuys();
	Player2.whoAmI();
	return (1);
}