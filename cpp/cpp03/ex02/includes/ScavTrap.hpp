/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:44:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 16:02:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(const std::string& newName);
		ScavTrap(const ScavTrap& to_copy);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap& rhs);
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif