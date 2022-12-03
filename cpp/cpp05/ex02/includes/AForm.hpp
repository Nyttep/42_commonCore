/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:30 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 15:53:23 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private :
		const std::string	_name;
		bool	_signed;
		const int	_gradeToSign;
		const int	_gradeToExec;
	public :
		AForm();
		AForm(const AForm& toCopy);
		AForm(std::string newName, int NewGradeToSign, int newGradeToExec);
		virtual ~AForm();
		AForm&	operator=(const AForm& toCopy);
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
		void	checkGradeExec(const Bureaucrat& executor) const;
		virtual void	beSigned(const Bureaucrat& signer);
		virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const AForm& toDisplay);

#endif