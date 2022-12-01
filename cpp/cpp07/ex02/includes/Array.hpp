/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:11:22 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 15:23:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdio>
#include <exception>
#include <stdexcept>

template<typename T>
class	Array
{
	private :
		T*	_data;
	public :
		Array<T>();
		Array<T>(const Array<T>& toCopy);
		Array<T>(size_t n);
		~Array<T>();
		Array<T>&	operator=(const Array<T>& toCopy);
		T&	operator[](size_t i);
		size_t	size();
};

#endif