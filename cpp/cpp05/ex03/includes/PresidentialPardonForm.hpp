/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:56:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 16:58:15 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		PresidentialPardonForm(std::string newTarget);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);
		virtual void	execute(const Bureaucrat& executor) const;
};

#endif