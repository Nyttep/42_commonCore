/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:16:18 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 15:10:42 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void	decr(T i)
{
	i--;
}

void	incr(int& i)
{
	i++;
}

template<typename T>
void	display(const T& i)
{
	std::cout << i;
}

int main()
{
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "array = ";
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	::iter<int>(arr, 10, &incr);
	std::cout << "array = ";
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	
	const char	str[10] = {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
	std::cout << "str = ";
	for (int i = 0; i < 10; i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;
	::iter<char>(str, 10, &display);
	std::cout << "str = ";
	for (int i = 0; i < 10; i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;

	return (0);
}