/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:57:39 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 17:04:29 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private :
		std::string	_ideas[100];
	public :
		Brain();
		Brain(const Brain& to_copy);
		~Brain();
		Brain&	operator=(const Brain& to_copy);
		std::string	getIdea(int i) const;
		void	setIdea(std::string newIdea, int i);
};

#endif