# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 21:14:22 by pdubois           #+#    #+#              #
#    Updated: 2022/01/06 00:35:49 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11

NAME = so_long
SRCS_NAME = main.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INCS_NAME = so_long.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
LIBS_NAME = libft.a \
			libmlx.a
LIBS_PATH = libft \
			minilibx
LIBS = $(addprefix $(LIBS_PATH)/, $(LIBS_NAME))
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} ${MLXFLAGS} -g -I ${INCS_PATH} -c $< -o $@

${LIBS}:
			cd ${LIBS_PATH}; make

${NAME}:	${OBJS} ${INCS} ${LIBS}
			${CC} -g -o ${NAME} ${OBJS} ${LIBS}
clean:
			${RM} ${OBJS}; cd libft; make clean

fclean:		clean
			${RM} ${NAME}; cd libft; make fclean

re:			fclean all

.PHONY : all clean fclean re
