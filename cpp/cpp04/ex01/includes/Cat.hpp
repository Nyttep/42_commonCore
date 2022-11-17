/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:59:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <new>
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
		virtual Brain*	getBrain() const;
		virtual void	setBrain(Brain* newBrain);
		virtual void	makeSound() const;
};

#endif