/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 16:10:05 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Player1("Player1");
	ScavTrap	guest;
	ScavTrap	Player2(Player1);
	
	Player1.attack(guest.getName());
	guest.takeDamage(Player1.getAD());
	guest.beRepaired(Player2.getAD());
	return (1);
}