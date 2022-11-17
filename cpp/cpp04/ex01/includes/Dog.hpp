/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 17:01:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
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
		Brain*	getBrain() const;
		void	setBrain(Brain* newBrain);
		void	makeSound() const;
};

#endif