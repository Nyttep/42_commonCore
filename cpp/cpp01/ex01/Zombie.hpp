/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:49:53 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/24 16:51:10 by pdubois          ###   ########.fr       */
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
		Zombie(void);
		~Zombie();
		void	announce(void);
		void	setName(std::string newName);
};

Zombie*	zombieHorde(int N, std::string name);
