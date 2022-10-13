/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:47:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/23 14:35:42 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie* ZombieHeap;

	randomChump("stack");
	ZombieHeap = newZombie("heap");
	ZombieHeap->announce();
	delete ZombieHeap;
	return (0);
}
