/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:32:31 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 13:55:49 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>

template<typename T>
typename T::iterator	easyfind(T &cont, int toFind)
{
	return(std::find(cont.begin(), cont.end(), toFind));
}

#endif