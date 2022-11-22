/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/22 18:05:36 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------------------- Constructors & Destructors ---------------------
Bureaucrat::Bureaucrat() : _name("not named"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy.getName()), _grade(toCopy.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string newName, int newGrade) : _name(newName)
{
	std::cout << "Bureaucrat args constructor called" << std::endl;
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = newGrade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

//------------------------- Operators Overloads -----------------------------
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& toDisplay)
{
	o << toDisplay.getName() << ", bureaucrat grade " << toDisplay.getGrade() << "." << std::endl;
	return (o);
}

//------------------------------ Exceptions -------------------------------
const char*	Bureaucrat::GradeTooHighException::what()const throw()
{
	return ("Grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what()const throw()
{
	return ("Grade is too low !");
}

//-------------------------- Setters & Getters ----------------------------
const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int newGrade)
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = newGrade;
}

//----------------------------- Other Functions ---------------------------
void	Bureaucrat::incrGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}
