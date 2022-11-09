/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:54 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/09 02:41:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		const std::string	_Name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string newName);
		ClapTrap(Claptrap to_copy);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap& to_copy);
		void	attack(const std::string& target);
};

#endif