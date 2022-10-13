/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:49:36 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/23 14:37:28 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	newZombie(std::string name)
{
	Zombie* newZombie;

	try
	{
		newZombie = new Zombie(name);
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "Error : " << ba.what() << "\n";
		return (NULL);
	}
	return (newZombie);
}