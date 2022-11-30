/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:55:07 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 19:01:18 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myFunctions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	Base*	p;

	p = generate();
	identify(p);
	identify(*p);
	delete p;
}