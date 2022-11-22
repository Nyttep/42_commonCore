/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:30 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/22 18:05:11 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class	Form
{
	private :
		const std::string	_name;
		bool	_signed;
		int	_gradeToSign;
		int	_gradeToExec;
	public :
		Form();
		Form(const Form& toCopy);
		Form(std::string newName, bool newSigned, int NewGradeToSign, int newGradeToExec);
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
		
}

#endif