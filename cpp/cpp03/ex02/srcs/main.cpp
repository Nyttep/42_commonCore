/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 17:13:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Player1("Player1");
	FragTrap	guest;
	FragTrap	Player2(Player1);
	
	Player1.attack(guest.getName());
	guest.takeDamage(Player1.getAD());
	guest.beRepaired(Player2.getAD());
	Player2.highFivesGuys();
	return (1);
}