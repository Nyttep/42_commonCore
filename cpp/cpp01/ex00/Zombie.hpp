/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:49:53 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/23 14:23:15 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <new>

class	Zombie
{
	private :
		std::string	name;
	public :
		Zombie(std::string newName);
		~Zombie();
		void	announce(void);
};

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);
