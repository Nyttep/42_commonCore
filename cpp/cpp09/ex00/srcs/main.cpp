/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:01:15 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/25 08:01:15 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkDB(std::string fName)
{
	std::ifstream	iFile;
	int				length;

	iFile.open(fName.c_str());
	if (!iFile.is_open())
	{
		std::cerr << "Error: The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
	iFile.seekg(0, iFile.end);
	length = iFile.tellg();
	if (length <= 0)
	{
		std::cerr << "Error: The file is empty\n";
		return (1);
	}
	iFile.seekg(0, iFile.beg);
	iFile.close();
	return (0);
}

int	checkArgs(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Program must be called like this :\n./btc <filename>";
		return (1);
	}
	std::string	fName = argv[1];
	if (checkDB(fName) == 1)
		return (1);
	return (0);
}

int	main(int argc, char** argv)
{
	BitcoinExchange	DBRate;

	if (checkArgs(argc, argv))
		return (1);
	if (DBRate.init())
		return (1);
	std::string			DBAmount = argv[1];
	if (DBRate.eval(DBAmount))
		return (1);
	return (0);
}