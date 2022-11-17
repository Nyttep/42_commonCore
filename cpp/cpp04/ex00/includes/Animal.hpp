/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:35:06 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:58:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <new>

class	Animal
{
	protected :
		std::string	_type;
	public :
		Animal();
		Animal(const Animal& to_copy);
		virtual ~Animal();
		Animal&	operator=(const Animal& to_copy);
		std::string	getType() const;
		void	setType(const std::string& newType);
		virtual void	makeSound() const;
};

#endif