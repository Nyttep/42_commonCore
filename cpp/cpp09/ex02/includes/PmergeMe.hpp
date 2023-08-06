/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:16:56 by pdubois           #+#    #+#             */
/*   Updated: 2023/08/06 17:16:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <stdlib.h>

class	PmergeMe
{
	private:
		std::vector<unsigned int>	_sortVect;
		std::deque<unsigned int>		_sortDeque;
	public:
		PmergeMe();
		PmergeMe(char** toSort);
		PmergeMe(const PmergeMe& toCopy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& toCopy);
		int	sort();
}