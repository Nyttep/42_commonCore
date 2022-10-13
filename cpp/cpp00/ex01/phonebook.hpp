/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:20:13 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/22 15:28:47 by pdubois          ###   ########.fr       */
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
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
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
