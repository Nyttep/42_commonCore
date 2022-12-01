/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:16:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 16:20:54 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int>	arr(10);

	arr[0] = 6;
	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "size of arr = " << arr.size() << std::endl;
	// arr[10]; // will crash because exception not catched
	return (0);
}