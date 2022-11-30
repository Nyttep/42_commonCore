/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myFunctions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:34:25 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:48:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myFunctions.hpp"


uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
