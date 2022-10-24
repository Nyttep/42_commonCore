/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 19:58:44 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ft_check_args(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Program must be called like this :\n mySed <filename> <string1> <string2>\n";
		return (1);
	}
	return (0);
}

int main(int argc, char** argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	if (ft_check_args(argc, argv) == 1)
		return (1);
	inputFile.open(argv[1]);
	if (!inputFile)
	{
		std::cerr << "The file can't be opened either because it doesn't exist or you don't have permissions\n";
		return (1);
	}
}