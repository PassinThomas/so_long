# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:24:59 by tpassin           #+#    #+#              #
#    Updated: 2024/02/05 16:48:22 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	get_next_line/get_next_line.c \
   	main.c \
	srcs/utils/ft_split.c \
	srcs/utils/utils_1.c \
	srcs/utils/utils_2.c \
	srcs/check_map/check_extension.c \
	srcs/check_map/check_rectangle.c \
	srcs/check_map/count_info.c \
	srcs/check_map/init_map.c \
	srcs/check_map/path_finding.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Wextra #-Werror

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -o $(NAME)

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re
