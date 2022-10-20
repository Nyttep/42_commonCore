/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:47:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/20 18:04:11 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie* ZombieHeap;

	randomChump("stack");
	ZombieHeap = newZombie("heap");
	if (ZombieHeap == NULL)
		return (1);
	ZombieHeap->announce();
	delete ZombieHeap;
	return (0);
}
