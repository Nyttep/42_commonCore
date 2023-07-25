# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 08:00:52 by pdubois           #+#    #+#              #
#    Updated: 2023/07/25 08:00:52 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = RPN

RM = rm -rf

SRCS_NAME =	main.cpp \
			RPN.cpp
SRCS_PATH =	srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

INCS_NAME =	RPN.hpp
INCS_PATH =	includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

%.o : %.cpp ${INCS}
	${CC} ${CFLAGS} -I ${INCS_PATH} -c $< -o $@

${NAME}: ${OBJS} ${INCS}
	${CC} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
