/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:31:56 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 13:55:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main()
{
	std::vector<int>	vect;
	std::list<int>	lst;

	for (int i = 0; i < 15; i = i + 2)
		vect.push_back(i);
	std::vector<int>::iterator	vect_iter = easyfind(vect, 1);
	if (vect_iter == vect.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vect_iter << std::endl;
	vect_iter = easyfind(vect, 2);
	if (vect_iter == vect.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vect_iter << std::endl;
	for (int i = 0; i < 15; i = i + 2)
		lst.push_back(i);
	std::list<int>::iterator	lst_iter = easyfind(lst, 1);
	if (lst_iter == lst.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *lst_iter << std::endl;
	lst_iter = easyfind(lst, 2);
	if (lst_iter == lst.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *lst_iter << std::endl;
}