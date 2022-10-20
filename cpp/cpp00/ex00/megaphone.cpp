/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:35:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/20 17:29:35 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main (int argc, char **argv)
{
	std::string	str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return (0);
	}
	for (int i = 1; argv[i] != NULL; i++)
	{
		str = argv[i];
		for (int j = 0; str[j] != 0; j++)
			str[j] = std::toupper(argv[i][j]);
		std::cout << str;
	}
	std::cout << "\n";
	return (0);
}