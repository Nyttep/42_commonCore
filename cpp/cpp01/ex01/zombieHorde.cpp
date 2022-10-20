/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:35:04 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/20 18:19:46 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	Horde;

	if (N <= 0)
	{
		std::cout << "Sorry, a Horde can't have less than one Zombie" << std::endl;
		return (NULL);
	}
	try
	{
		Horde = new Zombie[N];
	}
	catch(std::bad_alloc& ba)
	{
		std::cerr << "Error : " << ba.what() << "\n";
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return (Horde);
}
