/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:10 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 15:59:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int	checkSpecialStr(const std::string arg)
{
	const std::string	strSet[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i <= 5; i++)
		if (arg == strSet[i])
			return (1);
	return (0);
}

int	checkStrings(std::string arg)
{
	const std::string	strSet[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	
	if (std::isprint(arg[0]) && !std::isdigit(arg[0]) && arg[0] != '-' && arg.length() != 1)
	{
		std::cerr << "argument shouldn't represent a string other than:\n";
		for (int i = 0; i <= 5; i++)
			std::cerr << strSet[i] << "\n";
		return (1);
	}
	return (0);
}

int	checkOperators(std::string arg)
{
	if (arg[0] == '-')
	{
		if (!arg[1])
		{
			std::cerr << "'-' operator should not be alone\n";
			return (1);
		}
		if (!std::isdigit(arg[1]))
		{
			std::cerr << "There must only be a numeric value after a '-' operator\n";
			return (1);
		}
	}
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == '+')
		{
			std::cerr << "'+' operator isn't accepted nor needed\n";
			return (1);
		}
		if (arg[i] == '-' && i != 0)
		{
			std::cerr << "'-' operator can only be at the begining of a number\n";
			return (1);
		}
	}
	return (0);
}

int	checkArgs(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Program must be called like this :\n./convert <arg>\n";
		return (1);
	}
	std::string	arg = argv[1];
	bool	isnum = 0;
	if (checkSpecialStr(arg))
		return (0);
	if (checkStrings(arg))
		return (1);
	if (checkOperators(arg))
		return (1);
	for (unsigned int i = 0; arg[i]; i++)
	{
		if (std::isdigit(arg[i]))
			isnum = 1;
		if (isnum && i != arg.length() - 1 && (!std::isdigit(arg[i]) && std::isprint(arg[i])) && arg[i] != '.')
		{
			std::cerr << "There must not be a character mixed with numbers other than an 'f' at the end to represent a float\n";
			return (1);
		}
		if (isnum && i == arg.length() - 1 && (!std::isdigit(arg[i]) && std::isprint(arg[i])) && arg[i] != 'f')
		{
			std::cerr << "There must not be a character mixed with numbers other than an 'f' at the end to represent a float\n";
			return (1);
		}
		if (isnum && i == arg.length() - 2 && arg[i] == '.' && !std::isdigit(arg[i + 1]))
		{
			std::cerr << "There must not be a character mixed with numbers other than an 'f' at the end to represent a float\n";
			return (1);
		}
	}
	return (0);
}
