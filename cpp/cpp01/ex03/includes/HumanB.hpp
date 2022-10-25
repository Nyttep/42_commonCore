/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:51 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 19:14:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class	HumanB
{
	private :
		Weapon*		myWeapon;
		std::string	name;
	public :
		HumanB(std::string myName);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &newWeapon);
};

#endif
