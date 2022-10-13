/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:35:04 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/24 16:56:21 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	Horde;

	Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return (Horde);
}
