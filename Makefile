# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:24:59 by tpassin           #+#    #+#              #
#    Updated: 2024/02/06 23:47:01 by marvin           ###   ########.fr        #
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

LFLAGS = -L./mlx_linux -lmlx -Ilmlx -lXext -lX11

MLX = mlx_linux/libmlx.a

# MLXL = 	@make -C ./mlx_linux


IFLAGS = -I./

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C ./mlx_linux
	${CC} ${OBJS} ${MLXL} ${LFLAGS} -o $(NAME)

%.o:%.c
	${CC} ${IFLAGS} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re
