/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:49:13 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/18 17:51:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include <new>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria**	_inventory;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource& toCopy);
		~MateriaSource();
		MateriaSource&	operator=(const MateriaSource& rhs);
		AMateria*	getMateria(int idx) const;
		virtual void	learnMateria(AMateria* toLearn);
		virtual AMateria*	createMateria(const std::string& type);
};

#endif