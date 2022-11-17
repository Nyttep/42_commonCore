/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:49:54 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:56:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string	_Name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(const std::string newName);
		ClapTrap(const ClapTrap& to_copy);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap& to_copy);
		int		getHP(void) const;
		void	setHP(int newHP);
		int		getEP(void) const;
		void	setEP(int newEP);
		int		getAD(void) const;
		void	setAD(int newAD);
		std::string	getName(void) const;
		void	setName(const std::string newName);
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
};

#endif