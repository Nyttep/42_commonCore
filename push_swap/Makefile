# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 21:14:22 by pdubois           #+#    #+#              #
#    Updated: 2021/12/17 22:00:00 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS_NAME = main.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INC_NAME = push_swap.h
INC_PATH = includes
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
RM = rm -rf
OBJS = $(SRCS:.c=.o)
LIBS = libft/libft.a

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -I ${INC_PATH} -c $< -o $@

${LIBS}:
			cd libft; make

${NAME}:	${OBJS} ${INC} ${LIBS}
			${CC} -o ${NAME} ${OBJS} ${LIBS}
clean:
			${RM} ${OBJS} ${OBJS_BONUS}; cd libft; make fclean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re