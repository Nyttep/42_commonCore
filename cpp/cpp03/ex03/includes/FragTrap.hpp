/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:36:05 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/15 17:37:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(const std::string& newName);
		FragTrap(const FragTrap& to_copy);
		~FragTrap(void);
		FragTrap&	operator=(const FragTrap& rhs);
		void	highFivesGuys(void);
};


#endif