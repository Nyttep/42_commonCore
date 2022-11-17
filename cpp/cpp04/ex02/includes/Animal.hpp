/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:35:06 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:59:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <new>
# include "Brain.hpp"

class	Animal
{
	protected :
		std::string	_type;
		Animal();
		Animal(const Animal& to_copy);
	public :
		virtual ~Animal();
		Animal&	operator=(const Animal& to_copy);
		std::string	getType() const;
		void	setType(const std::string& newType);
		virtual Brain*	getBrain() const = 0;
		virtual void	setBrain(Brain* newBrain) = 0;
		virtual void	makeSound() const = 0;
};

#endif
