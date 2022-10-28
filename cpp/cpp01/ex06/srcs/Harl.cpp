/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:32:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/27 17:09:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::_debug(void)
{
	std::cout <<  "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n" << std::endl;
}

void	Harl::_info(void)
{
	std::cout <<  "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout <<  "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::_error(void)
{
	std::cout <<  "[ ERROR ]\nThis is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::_other(void)
{
	std::cout <<  "My name is misspelled on the cup. Do you know who I am ?\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	switchArray[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	int			i = 0;

	while (switchArray[i] != level && switchArray[i] != "")
		i++;
	switch (i)
	{
		case (0):
			_debug();
			__attribute__((fallthrough));
		case (1):
			_info();
			__attribute__((fallthrough));
		case (2):
			_warning();
			__attribute__((fallthrough));
		case (3):
			_error();
			break;
		default:
			_other();
	}
}
