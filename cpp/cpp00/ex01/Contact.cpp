/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:34:32 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/20 17:48:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	Contact::getFirstName(void) const
{
	return (this->FirstName);
}

void	Contact::setFirstName(std::string newName)
{
	this->FirstName = newName;
}

std::string	Contact::getLastName(void) const
{
	return (this->LastName);
}

void	Contact::setLastName(std::string newName)
{
	this->LastName = newName;
}

std::string	Contact::getNickName(void) const
{
	return (this->NickName);
}

void	Contact::setNickName(std::string newName)
{
	this->NickName = newName;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->PhoneNumber);
}

void	Contact::setPhoneNumber(std::string newNumber)
{
	this->PhoneNumber = newNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->DarkestSecret);
}

void	Contact::setDarkestSecret(std::string newSecret)
{
	this->DarkestSecret = newSecret;
}
