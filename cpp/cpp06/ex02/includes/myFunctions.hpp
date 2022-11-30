/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myFunctions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:40:21 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 18:43:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFUNCTIONS_HPP
# define MYFUNCTIONS_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif