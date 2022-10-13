/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:20:12 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/17 06:25:20 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	error()
{
	if (errno != 0)
	{
		std::cerr << "Sorry, something unexpected happened, exiting the program\n";
		return (1);
	}
	return (0);
}

int	main()
{
	PhoneBook	MyPhoneBook;
	std::string		UserInput;

	std::cout << "Welcome to your Phonebook !\n";
	while (1)
	{
		std::cout << "Would you like to ADD, SEARCH or EXIT ?" << std::endl;
		std::getline(std::cin, UserInput);
		if (error() == 1)
			return (errno);
		if (UserInput == "EXIT")
			return (0);
		if (UserInput == "ADD")
			MyPhoneBook.add();
		else if (UserInput == "SEARCH")
			MyPhoneBook.search();
		if (error() == 1)
			return (errno);
	}
	return (0);
}
