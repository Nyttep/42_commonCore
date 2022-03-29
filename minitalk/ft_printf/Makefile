CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

SRCS =	ft_printf.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			ar rc $@ $^

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY : all clean fclean re
