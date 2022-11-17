/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:00:31 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 16:55:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include <new>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice& to_copy);
		~Ice();
		Ice&	operator=(const Ice& rhs);
		virtual AMateria*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif