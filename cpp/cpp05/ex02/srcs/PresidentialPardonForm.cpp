/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:56:36 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:16:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//-------------------- Constructors & Destructors --------------------
PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("no target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : AForm("presidential pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = toCopy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("presidential pardon", 25, 5), _target(newTarget)
{
	std::cout << "PresidentialPardonForm args constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

//--------------------- Operators overload ------------------------
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	this->_target = toCopy._target;
	return (*this);
}

//---------------------- Other Functions --------------------------
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkGradeExec(executor);
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox !" << std::endl;
}

