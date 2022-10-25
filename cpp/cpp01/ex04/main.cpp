/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/25 16:18:34 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ft_check_args(int argc, char** argv)
{
	(void)argv;
	if (argc != 4)
	{
		std::cerr << "Program must be called like this :\n ./mySed <filename> <string1> <string2>\n";
		return (1);
	}
	return (0);
}

int	ft_read_inputFile(std::ifstream &iFile, std::string &buffer)
{
	int			length;

	iFile.seekg(0, iFile.end);
	length = iFile.tellg();
	iFile.seekg(0, iFile.beg);
	if (length == -1)
	return (1);
	buffer.resize(length);
	iFile.read(&buffer[0], length);
	return (0);
}

std::string	ft_search_replace(std::string buffer, std::string s1, std::string s2)
{
	size_t	pos;

	while (buffer.find(s1) != std::string::npos)
	{
		pos = buffer.find(s1);
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
	}
	return (buffer);
}

int main(int argc, char** argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		buffer;

	if (ft_check_args(argc, argv) == 1)
		return (1);
	std::string		filename = argv[1];
	inputFile.open(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
	if (ft_read_inputFile(inputFile, buffer) == 1)
	{
		std::cerr << "Sorry, the input vile does not seem to be valid\n";
		inputFile.close();
		return (1);
	}
	if (!inputFile)
	{
		std::cerr << " Sorry, an error happened while reading the input file\n";
		inputFile.close();
		return (1);
	}
	inputFile.close();
	buffer = ft_search_replace(buffer, argv[2], argv[3]);
	outputFile.open((filename + ".replace").c_str());
	outputFile.write(buffer.c_str(), buffer.length());
	outputFile.close();
}