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
MLXFLAGS = -lXext -lX11

NAME = so_long
SRCS_NAME = main.c \
			get_next_line.c \
			get_next_line_utils.c \
			clean_exit_1.c \
			clean_exit_2.c \
			initialization_1.c \
			initialization_2.c \
			check_1.c \
			check_2.c \
			so_long_utils.c \
			display_utils.c \
			key_events.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INCS_NAME = so_long.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
LIBS = libft/libft.a \
		ft_printf/ft_printf.a \
		minilibx/libmlx_Linux.a
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -g -I ${INCS_PATH} -I libft -I minilibx -I ft_printf -c $< -o $@

${LIBS}:
			make -C libft; make -C ft_printf; make -C minilibx

${NAME}:	${OBJS} ${INCS} ${LIBS}
			${CC} -g -o ${NAME} ${OBJS} ${LIBS} ${MLXFLAGS}
clean:
			${RM} ${OBJS}; make -C libft clean; make -C minilibx clean; make -C ft_printf clean

fclean:		clean
			${RM} ${NAME}; make -C libft fclean; make -C minilibx fclean; make -C ft_printf fclean

re:			fclean all

.PHONY : all clean fclean re
