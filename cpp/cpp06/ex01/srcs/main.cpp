/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:25:57 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:47:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "myFunctions.hpp"
#include <new>

int	main()
{
	Data* raw = new Data();
	std::cout << "adress of data at the beginning : " << raw << std::endl;
	raw = deserialize(serialize(raw));
	std::cout << "adress of data at the end : " << raw << std::endl;
	delete raw;
	return (0);
}