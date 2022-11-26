/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:27:21 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:56:26 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//------------------- Construtors & Destructors ---------------------
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& toCopy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = toCopy;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}

//--------------------- Operators Overload ----------------------
Intern&	Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	return (*this);
}

//----------------------- Other Functions ----------------------
AForm*	Intern::makeForm(std::string formName, std::string target)
{
	int	i = 3;
	AForm**	Forms = new AForm*[i--];
	AForm*	ret;
	
	Forms[0] = new ShrubberyCreationForm(target);
	Forms[1] = new RobotomyRequestForm(target);
	Forms[2] = new PresidentialPardonForm(target);
	while (i >= 0)
	{
		if (Forms[i]->getName() == formName)
		{
			for (int j = i + 1; j <= 2; j++)
				delete Forms[j];
			for (int j = i - 1; j >= 0; j--)
				delete Forms[j];
			std::cout << "Intern creates " << formName << std::endl;
			ret = Forms[i];
			delete [] Forms;
			return (ret);
		}
		i--;
	}
	std::cerr << "Form " << formName << " doesn't exist\n";
	return (NULL);
}