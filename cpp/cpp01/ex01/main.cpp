/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:31:35 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/20 18:20:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	Zombie* Horde;
	int		N = 5;

	Horde = zombieHorde(N, "horde");
	if (Horde == NULL)
		return (1);
	while (N-- > 0)
		Horde[N].announce();
	delete[] Horde;
}
