/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:00:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 12:06:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& lhs, T& rhs)
{
	T tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
T	min(const T& lhs, const T& rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
T	max(const T& lhs, const T& rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

#endif