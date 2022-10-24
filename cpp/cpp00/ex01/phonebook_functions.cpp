/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_functions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:26:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 15:59:20 by pdubois          ###   ########.fr       */
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
	i = to_add % 8;
	MyContacts[i].resetContact();
	while (MyContacts[i].getFirstName() == "" && !std::cin.eof())
	{
		std::cout << "Enter the first name of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].setFirstName(UserInput);
	}
	while (MyContacts[i].getLastName() == "" && !std::cin.eof())
	{
		std::cout << "Enter the last name of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].setLastName(UserInput);
	}
	while (MyContacts[i].getNickName() == "" && !std::cin.eof())
	{
		std::cout << "Enter the nickname of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].setNickName(UserInput);
	}
	while (MyContacts[i].getPhoneNumber() == "" && !std::cin.eof())
	{
		std::cout << "Enter the phone number of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].setPhoneNumber(UserInput);
	}
	while (MyContacts[i].getDarkestSecret() == "" && !std::cin.eof())
	{
		std::cout << "Enter the darkest secret of the contact you would like to add :" << std::endl;
		std::getline(std::cin, UserInput);
		MyContacts[i].setDarkestSecret(UserInput);
	}
	if (error() == 1 || std::cin.eof())
		return (1);
	to_add++;
	std::cout << "Contact successfully added" << std::endl;
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
	int	to_display = to_add;
	if (this->to_add > 8)
		to_display = 8;
	for (int i = 0; i < to_display; i++)
	{
		std::cout.width(10);
		std::cout<< std::right <<  i << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].getFirstName()) << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].getLastName()) << "|";
		std::cout.width(10);
		std::cout<< std::right <<  ft_strtrunc(MyContacts[i].getNickName()) << std:: endl;
	}
	return ;
}

void	PhoneBook::ft_display_contact(int index)
{
	std::cout << MyContacts[index].getFirstName() << std::endl;
	std::cout << MyContacts[index].getLastName() << std::endl;
	std::cout << MyContacts[index].getNickName() << std::endl;
	std::cout << MyContacts[index].getPhoneNumber() << std::endl;
	std::cout << MyContacts[index].getDarkestSecret() << std::endl;
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
	while (index < 0 || index > 7 || (index >= to_add && to_add <= 7) || UserInput.length() != 1)
	{
		index = -1;
		std::cout << "Please enter the index of the contact you want to see :" << std::endl;
		std::getline(std::cin, UserInput);
		if (std::cin.eof())
			return (0);
		if (std::isdigit(UserInput[0]))
			std::istringstream(UserInput) >> index;
		if (index >= 0 && index <= 7 && index < to_add && UserInput.length() == 1)
			ft_display_contact(index);
		else
			std::cerr << "Not a valid index" << std::endl;
	}
	return (0);
}
