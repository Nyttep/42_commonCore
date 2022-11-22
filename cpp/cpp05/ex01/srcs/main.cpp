/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:37:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/22 18:06:25 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	A("Karen", 150);
	Bureaucrat	B("Paul", 1);
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
	// B.incrGrade(); //Crash the program because exception not catch
	return (0);
}