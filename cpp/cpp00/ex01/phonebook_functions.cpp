/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_functions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:26:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/22 15:39:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phonebook.hpp>

PhoneBook::PhoneBook()
{
	to_add = -1;
}

int	PhoneBook::add()
{
	std::string	UserInput;
	int		i = 0;

	if (to_add == -1)
		to_add++;
	i = to_add;
	while (MyContacts[i].FirstName == "")
	{
		std::cout << "Enter the first name of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].FirstName = UserInput;
	}
	while (MyContacts[i].LastName == "")
	{
		std::cout << "Enter the last name of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].LastName = UserInput;
	}
	while (MyContacts[i].Nickname == "")
	{
		std::cout << "Enter the nickname of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].Nickname = UserInput;
	}
	while (MyContacts[i].PhoneNumber == "")
	{
		std::cout << "Enter the phone number of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].PhoneNumber = UserInput;
	}
	while (MyContacts[i].DarkestSecret == "")
	{
		std::cout << "Enter the darkest secret of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].DarkestSecret = UserInput;
	}
	if (error() == 1)
		return (1);
	std::cout << "Contact successfully added" << std::endl;
	if (++to_add == 8)
		to_add = 0;
	return (0);
}

std::string	ft_strtrunc(std::string str)
{
	if (str.length() < 10)
		return (str);
	str.erase(9, str.length() - 1);
	return (str + ".");
}

void	PhoneBook::ft_display_menu()
{
	for (int i = 0; i < to_add; i++)
	{
		std::cout.width(10);
		std::cout<< std::right <<  i << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].FirstName) << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].LastName) << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].Nickname) << std:: endl;
	}
	return ;
}

void	PhoneBook::ft_display_contact(int index)
{
	std::cout << MyContacts[index].FirstName << std::endl;
	std::cout << MyContacts[index].LastName << std::endl;
	std::cout << MyContacts[index].Nickname << std::endl;
	std::cout << MyContacts[index].PhoneNumber << std::endl;
	std::cout << MyContacts[index].DarkestSecret << std::endl;
}

int	PhoneBook::search()
{
	std::string		UserInput;
	int				index = -1;

	if (to_add == -1)
	{
		std::cout << "You don't have any saved contacts :/" << std::endl;
		return (0);
	}
	std::cout << "Here are your saved contacts :\n";
	ft_display_menu();
	while (index < 0 || index > 7 || index >= to_add || UserInput.length() != 1)
	{
		std::cout << "Please enter the index of the contact you want to see :" << std::endl;
		std::getline(std::cin, UserInput);
		if (std::isdigit(UserInput[0]))
			std::istringstream(UserInput) >> index;
		if (index >= 0 && index <= 7 && index < to_add && UserInput.length() == 1)
			ft_display_contact(index);
		else
			std::cerr << "Not a valid index" << std::endl;
	}
	return (0);
}
