/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:16:31 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 15:11:36 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdio>

template<typename T>
void	iter(T* arr, size_t size, void (*fctPtr)(T&))
{
	while (size > 0)
	{
		size--;
		fctPtr(arr[size]);
	}
}

template<typename T>
void	iter(const T* arr, size_t size, void (*fctPtr)(const T&))
{
	while (size > 0)
	{
		size--;
		fctPtr(arr[size]);
	}
}

#endif