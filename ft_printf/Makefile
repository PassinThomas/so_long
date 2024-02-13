SRC	=	ft_printf \
ft_print_hex \
ft_putchar \
ft_putnbr \
ft_putstr \
ft_unsigned_nb \
ft_put_p \

SRCS 	= $(addsuffix .c, ${SRC})

OBJS	= ${SRCS:.c=.o}

CC	= cc
RM	= rm -f
AR	= ar rc

CFLAGS	= -Wall -Werror -Wextra

NAME = libftprintf.a

all:		${NAME}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}		

%o :%c
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re
