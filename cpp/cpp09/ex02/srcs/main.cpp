/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:16:49 by pdubois           #+#    #+#             */
/*   Updated: 2023/08/06 17:16:49 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkArgs(int argc, char**argv)
{
	unsigned int i = 1;
	unsigned int j = 0;

	if (argc == 1)
	{
		std::cerr << "Error: no numbers to sort\n";
		return (1);
	}
	while(argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!std::isdigit(argv[i][j]))
			{
				std::cerr << "Error: arguments should only be positive integers\n";
				return (1);
			}
			j++;
		}
		if (atol(argv[i]) > 2147483647 || std::strlen(argv[i]) > 12)
		{
			std::cerr << "Error: at least one of the integers is greater than INTMAX\n";
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char** argv)
{
	if (checkArgs(argc, argv))
		return (1);
	PmergeMe	FJMI(&argv[1]);
	FJMI.printUnsorted();
	std::clock_t begTimerVect = std::clock();
	// FJMI.sortVect();
	std::clock_t endTimerVect = std::clock();
	std::clock_t begTimerDeque = std::clock();
	FJMI.sortDeque();
	std::clock_t endTimerDeque = std::clock();
	FJMI.printSorted();
	std::cout << std::setprecision(5) << "Time to sort with std::vector = " << 1000 * float(endTimerVect - begTimerVect) / CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::setprecision(5) << "Time to sort with std::deque = " << 1000 * float(endTimerDeque - begTimerDeque) / CLOCKS_PER_SEC << "ms" << std::endl;
	return (0);
}