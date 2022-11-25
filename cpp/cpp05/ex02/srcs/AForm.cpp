/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/25 15:35:45 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//------------- Constructors & Destructors ---------------
AForm::AForm() : _name("not named"), _signed(0), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm default Constructor called" << std::endl;
}

AForm::AForm(const AForm& toCopy) : _name(toCopy._name)
{
	*this = toCopy;
	std::cout << "AForm copy Constructor called" << std::endl;
}

AForm::AForm(std::string newName, int NewGradeToSign, int newGradeToExec) : _name(newName), _signed(0)
{
	if (NewGradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (NewGradeToSign > 150)
		throw AForm::GradeTooLowException();
	else
		_gradeToSign = NewGradeToSign;
	if (newGradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (newGradeToExec > 150)
		throw AForm::GradeTooLowException();
	else
		_gradeToExec = newGradeToExec;
	std::cout << "AForm args Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm default Destructor called" << std::endl;
}

//-------------- Operators Overload ---------------------
AForm& AForm::operator=(const AForm& toCopy)
{
	this->_signed = toCopy._signed;
	this->_gradeToSign = toCopy._gradeToSign;
	this->_gradeToExec = toCopy._gradeToExec;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const AForm& toDisplay)
{
	o << "AForm " << toDisplay.getName();
	if (toDisplay.getSigned())
		o << " is signed and iot needs a bureaucrat with a grade of " << toDisplay.getGradeToExec() << " to be executed" << std::endl;
	else
		o << " is not signed and it needs a bureaucrat with a grade of " << toDisplay.getGradeToSign() << " to be signed  and a bureaucrat with a grade of " << toDisplay.getGradeToExec() << " to be executed" << std::endl;;
	return (o);
}

//----------------- Exceptions ------------------------
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("This form is already signed");
}

//------------ Setters & Getters ---------------------
const std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

//---------------- Other Functions ------------------
void	AForm::checkGradeExec(const Bureaucrat& executor) const
{
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (_signed)
		throw AForm::AlreadySignedException();
	else if (signer.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = 1;
}
