/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/27 17:36:18 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class	HumanA
{
	private :
		Weapon&		myWeapon;
		std::string	name;
	public :
		HumanA(std::string myName, Weapon newWeapon);
		void	attack(void);
};

