/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:55:02 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:15:34 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//-------------------- Constructors & Destructors --------------------
RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("no target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : AForm("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = toCopy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("robotomy request", 72, 45), _target(newTarget)
{
	std::cout << "RobotomyRequestForm args constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

//--------------------- Operators overload ------------------------
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	this->_target = toCopy._target;
	return (*this);
}

//---------------------- Other Functions --------------------------
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkGradeExec(executor);
	unsigned int	i;

	std::cout << "* Bzzzzzzzzzzzzzzzzz bzzzzz bzzzzz bzzzzzz bzzzzzzzzzzzzzzzzzzz *" << std::endl;
	std::srand(std::time(NULL));
	i = std::rand();
	if (i % 2 == 0)
		std::cout << _target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Sorry, we failed to robotomize " << _target << std::endl;
}

