/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:13:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 14:59:39 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include <new>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(const WrongCat& to_copy);
		~WrongCat();
		WrongCat&	operator=(const WrongCat& to_copy);
		void	makeSound() const;
};

#endif