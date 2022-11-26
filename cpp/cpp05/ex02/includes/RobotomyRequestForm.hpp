/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:52:10 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 16:29:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		RobotomyRequestForm(std::string newTarget);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);
		virtual void	execute(const Bureaucrat& executor) const;
};

#endif