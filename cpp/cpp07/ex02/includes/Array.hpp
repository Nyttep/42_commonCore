/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:11:22 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 16:20:07 by pdubois          ###   ########.fr       */
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
		size_t	_size;
	public :
		Array<T>()
		{
			std::cout << "Array default constructor called" << std::endl;
			_data = new T[0]();
			_size = 0;
		}
		Array<T>(const Array<T>& toCopy)
		{
			std::cout << "Array copy constructor called" << std::endl;
			*this = toCopy;
		}
		Array<T>(size_t n)
		{
			std::cout << "Array args constructor called" << std::endl;
			_data = new T[n]();
			_size = n;
		}
		~Array<T>()
		{
			std::cout << "Array default destructor called" << std::endl;
			delete [] _data;
		}
		Array<T>&	operator=(const Array<T>& toCopy)
		{
			this->_size = toCopy.size();
			delete [] _data;
			_data = new T[toCopy.size()]();
			for (int i = 0; 1; i++)
			{
				try
				{
					_data[i] = toCopy[i];
				}
				catch (std::exception& e)
				{
					return (*this);
				}
			}
		}
		T&	operator[](size_t i)
		{
			if (i >= size())
				throw std::exception();
			return (_data[i]);
		}
		size_t	size()
		{
			return (_size);
		}
};

#endif