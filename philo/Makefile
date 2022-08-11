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

CC = cc
CFLAGS = -pthread -Wall -Wextra -Werror

NAME = philo
SRCS_NAME = main.c \
			handle_philo.c \
			philo_utils.c \
			free_utils.c \
			check_args.c \
			time_utils.c \
			death_related.c \
			actions.c \
			actions_utils.c \
			turns.c \
			init_mutex.c \

SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

INCS_NAME = philo.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))

LIBS = libft/libft.a \

RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -g -I ${INCS_PATH} -I libft -c $< -o $@

${LIBS}:
			make -C libft

${NAME}:	${OBJS} ${INCS} ${LIBS}
			${CC} -pthread -o ${NAME} ${OBJS} ${LIBS}
clean:
			${RM} ${OBJS}; make -C libft fclean 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re
