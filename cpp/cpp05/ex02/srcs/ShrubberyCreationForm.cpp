/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:32 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:15:05 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//-------------------- Constructors & Destructors --------------------
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("no target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm("shrubbery creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = toCopy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("shrubbery creation", 145, 137), _target(newTarget)
{
	std::cout << "ShrubberyCreationForm args constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

//--------------------- Operators overload ------------------------
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	this->_target = toCopy._target;
	return (*this);
}

//---------------------- Other Functions --------------------------
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkGradeExec(executor);
	std::ofstream	output;
	std::string	buffer;

	output.open((_target + "_shrubbery").c_str());
	buffer = "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n       | |     \n       | |     \n      // \\\\";
	output.write(buffer.c_str(), buffer.length());
	output.close();
}

