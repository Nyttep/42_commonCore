/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:35:06 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:15:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected :
		std::string	_type;
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal& to_copy);
		~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& to_copy);
		std::string	getType() const;
		void	setType(const std::string& newType);
		void	makeSound() const;
};

#endif