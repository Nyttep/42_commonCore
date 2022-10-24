/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:20:13 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 15:53:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <cerrno>

int	error();

class	Contact
{
	public :
		std::string	getFirstName(void) const;
		void		setFirstName(std::string newName);
		std::string	getLastName(void) const;
		void		setLastName(std::string newName);
		std::string	getNickName(void) const;
		void		setNickName(std::string newName);
		std::string	getPhoneNumber(void) const;
		void		setPhoneNumber(std::string newNumber);
		std::string	getDarkestSecret(void) const;
		void		setDarkestSecret(std::string newSecret);
		void		resetContact(void);
	private :
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
};

class	PhoneBook
{
	private :
		Contact MyContacts[8];
		int		to_add;
		void	ft_display_menu();
		void	ft_display_contact(int index);
	public :
		int		add();
		int		search();
		PhoneBook();
};
