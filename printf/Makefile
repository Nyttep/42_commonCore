CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS =	ft_printf.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			ar rc $@ $^

bonus:		${OBJS_BONUS}
			ar rc ${NAME} $^

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
