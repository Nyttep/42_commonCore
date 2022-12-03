/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 16:00:00 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//------------- Constructors & Destructors ---------------
Form::Form() : _name("not named"), _signed(0), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default Constructor called" << std::endl;
}

Form::Form(const Form& toCopy) : _name(toCopy._name), _gradeToSign(toCopy.getGradeToSign()), _gradeToExec(toCopy.getGradeToExec())
{
	*this = toCopy;
	std::cout << "Form copy Constructor called" << std::endl;
}

Form::Form(std::string newName, int NewGradeToSign, int newGradeToExec) : _name(newName), _signed(0), _gradeToSign(NewGradeToSign), _gradeToExec(newGradeToExec)
{
	if (NewGradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (NewGradeToSign > 150)
		throw Form::GradeTooLowException();
	if (newGradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (newGradeToExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form args Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form default Destructor called" << std::endl;
}

//-------------- Operators Overload ---------------------
Form& Form::operator=(const Form& toCopy)
{
	this->_signed = toCopy._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Form& toDisplay)
{
	o << "Form " << toDisplay.getName();
	if (toDisplay.getSigned())
		o << " is signed and iot needs a bureaucrat with a grade of " << toDisplay.getGradeToExec() << " to be executed" << std::endl;
	else
		o << " is not signed and it needs a bureaucrat with a grade of " << toDisplay.getGradeToSign() << " to be signed  and a bureaucrat with a grade of " << toDisplay.getGradeToExec() << " to be executed" << std::endl;;
	return (o);
}

//----------------- Exceptions ------------------------
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("This form is already signed");
}

//------------ Setters & Getters ---------------------
const std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

//---------------- Other Functions ------------------
void	Form::beSigned(const Bureaucrat& signer)
{
	if (_signed)
		throw Form::AlreadySignedException();
	else if (signer.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}
