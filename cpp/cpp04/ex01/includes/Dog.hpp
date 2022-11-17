/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:59:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <new>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private :
		Brain*	_myBrain;
	public :
		Dog();
		Dog(const Dog& to_copy);
		~Dog();
		Dog&	operator=(const Dog& to_copy);
		virtual Brain*	getBrain() const;
		virtual void	setBrain(Brain* newBrain);
		virtual void	makeSound() const;
};

#endif