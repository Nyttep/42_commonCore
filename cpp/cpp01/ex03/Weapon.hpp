/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:56 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/27 17:25:35 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	private :
		std::string	type;
	public :
		Weapon(std::string newType);
		const std::string&	getType(void);
		void	setType(std::string newType);
};

#endif
