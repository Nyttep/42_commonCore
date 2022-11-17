/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:44:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 18:04:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		const std::string	_name;
		AMateria[4]	_inventory;
	public :
		Character();
		Character(const Character& to_copy);
		Character(const std::string newName);
		~Character();
		Character&	operator=(const Character& rhs);
		virtual const std::string& getName() const;
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);

};

#endif