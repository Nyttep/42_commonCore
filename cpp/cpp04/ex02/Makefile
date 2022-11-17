# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 04:26:20 by pdubois           #+#    #+#              #
#    Updated: 2022/11/16 16:06:46 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = a.out

RM = rm -rf

SRCS_NAME =	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
			Brain.cpp
SRCS_PATH =	srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

INCS_NAME =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Brain.hpp
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))

OBJS = ${SRCS:.cpp=.o}
OBJS_DIR = .objdir

all: ${NAME}

%.o : %.cpp ${INCS}
			${CC} ${CFLAGS} -I ${INCS_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INCS}
			${CC} -o ${NAME} ${OBJS}
			@mkdir ${OBJS_DIR} 2> /dev/null; mv ${SRCS_PATH}/*.o .objdir

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re