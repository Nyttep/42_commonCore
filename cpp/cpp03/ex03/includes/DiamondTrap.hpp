/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:11 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:56:45 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string	_Name;
	public :
		DiamondTrap(void);
		DiamondTrap(const std::string& newName);
		DiamondTrap(const DiamondTrap& to_copy);
		~DiamondTrap(void);
		DiamondTrap&	operator=(const DiamondTrap& rhs);
		void	attack(const std::string& target);
		void	whoAmI(void) const;
};

#endif