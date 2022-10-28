/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:48:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/27 16:39:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	ft_check_args(int argc, char** argv)
{
	(void) argv;
	if (argc != 2)
		return (1);
	return (0);
}

int	main(int argc, char** argv)
{
	Harl	myHarl;

	if (ft_check_args(argc, argv) == 1)
	{
		std::cerr << "Program should be called like this :\n./HarlFilter <level>\n";
		return (1);
	}
	myHarl.complain(argv[1]);
	return (0);
}