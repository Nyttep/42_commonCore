/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:50:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 16:55:36 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include <new>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure& to_copy);
		~Cure();
		Cure&	operator=(const Cure& rhs);
		virtual AMateria*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif