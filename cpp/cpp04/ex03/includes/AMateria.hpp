/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:46:01 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 18:58:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMETERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		const std::string	_type;
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& to_copy);
	public:
		virtual ~AMateria();
		AMateria&	operator=(const AMateria& rhs);
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);
};

#endif