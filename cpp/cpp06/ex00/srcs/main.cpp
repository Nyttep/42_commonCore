/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:48:14 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:21:35 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
# include "Converter.hpp"

int	main(int argc, char** argv)
{
	if (checkArgs(argc, argv))
		return (1);
	std::string arg = argv[1];
	Converter	conv(arg);

	if (conv.getType() == "char")
	{
		char c = static_cast<char>(arg[0]);
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		std::cout << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "int")
	{
		int i = std::atoi(arg.c_str());
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'\n";
		std::cout << "int: ";
		if (std::atol(arg.c_str()) > std::numeric_limits<int>::max() || std::atol(arg.c_str()) < std::numeric_limits<int>::min() || arg.length() > 11)
			std::cout << "impossible\n";
		else
			std::cout << i << "\n";
		std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "float")
	{
		float f = std::atof(arg.c_str());
		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);
		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << c << "\n";
		std::cout << "int: ";
		if (std::atol(arg.c_str()) > std::numeric_limits<int>::max() || std::atol(arg.c_str()) < std::numeric_limits<int>::min() || arg.length() > 11)
			std::cout << "impossible\n";
		else
			std::cout << i << "\n";
		std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "double")
	{
		double d = std::atof(arg.c_str());
		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		float f = static_cast<float>(d);
		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << c << "\n";
		std::cout << "int: ";
		if (std::atol(arg.c_str()) > std::numeric_limits<int>::max() || std::atol(arg.c_str()) < std::numeric_limits<int>::min() || arg.length() > 11)
			std::cout << "impossible\n";
		else
			std::cout << i << "\n";
		std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "-inff")
	{
		float f = std::numeric_limits<float>::infinity() * -1;
		double d = static_cast<double>(f);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "+inff")
	{
		float f = std::numeric_limits<float>::infinity();
		double d = static_cast<double>(f);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		double d = static_cast<double>(f);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "-inf")
	{
		double d = std::numeric_limits<double>::infinity() * -1;
		float f = static_cast<float>(d);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "+inf")
	{
		double d = std::numeric_limits<double>::infinity();
		float f = static_cast<float>(d);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	else if (conv.getType() == "nan")
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		float f = static_cast<float>(d);
		std::cout << "char: impossible\nint: impossible\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
	return (0);
}
