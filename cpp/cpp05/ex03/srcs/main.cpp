/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:37:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:53:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	A("Karen", 150);
	Bureaucrat	B("Paul", 1);
	Intern	someRandomIntern;
	AForm*	F = someRandomIntern.makeForm("shrubbery creation", "garden");

	try
	{
		Bureaucrat	C("Fraud", 0);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		A.decrGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// B.incrGrade(); //Crash the program because exception not catched
	A.signForm(*F);
	B.signForm(*F);
	B.signForm(*F);
	A.executeForm(*F);
	B.executeForm(*F);
	delete F;
	F = someRandomIntern.makeForm("robotomy request", "Dr.Gero");
	B.executeForm(*F);
	delete F;
	F = someRandomIntern.makeForm("presidential pardon", "Marvin");
	B.executeForm(*F);
	delete F;
	return (0);
}