/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 14:26:15 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <new>
# include "Animal.hpp"

class	Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat& to_copy);
		~Cat();
		Cat&	operator=(const Cat& to_copy);
		void	makeSound() const;
};

#endif