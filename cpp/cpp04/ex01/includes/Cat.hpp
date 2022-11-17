/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 17:02:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private :
		Brain*	_myBrain;
	public :
		Cat();
		Cat(const Cat& to_copy);
		~Cat();
		Cat&	operator=(const Cat& to_copy);
		Brain*	getBrain() const;
		void	setBrain(Brain* newBrain);
		void	makeSound() const;
};

#endif