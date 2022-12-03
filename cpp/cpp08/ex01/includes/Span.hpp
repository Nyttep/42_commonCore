/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:23:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 18:20:00 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <stdexcept>
# include <limits>
# include <iterator>
# include <cstdlib>
# include <ctime>

class	Span
{
	private :
		std::vector<int>	_vect;
		const unsigned int	_max;
		Span();
	public :
		Span(int newMax);
		Span(const Span& toCopy);
		~Span();
		Span&	operator=(const Span& toCopy);
		void	addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	fillRandom(unsigned int n);
		template<class T>
		void	assign(T pos1, T pos2)
		{
			_vect.assign(pos1, pos2);
		}
};

#endif