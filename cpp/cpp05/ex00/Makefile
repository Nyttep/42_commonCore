# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 04:26:20 by pdubois           #+#    #+#              #
#    Updated: 2022/11/21 14:26:30 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = a.out

RM = rm -rf

SRCS_NAME =	main.cpp \
			Bureaucrat.cpp
SRCS_PATH =	srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

INCS_NAME =	Bureaucrat.hpp
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

%.o : %.cpp ${INCS}
			${CC} ${CFLAGS} -I ${INCS_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INCS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re