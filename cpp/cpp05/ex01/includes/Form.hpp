/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:30 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 15:53:01 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private :
		const std::string	_name;
		bool	_signed;
		const int	_gradeToSign;
		const int	_gradeToExec;
	public :
		Form();
		Form(const Form& toCopy);
		Form(std::string newName, int NewGradeToSign, int newGradeToExec);
		~Form();
		Form&	operator=(const Form& toCopy);
		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	AlreadySignedException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		const std::string	getName() const;
		bool	getSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExec() const;
		void	beSigned(const Bureaucrat& signer);
};

std::ostream&	operator<<(std::ostream& o, const Form& toDisplay);

#endif