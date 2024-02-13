# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:24:59 by tpassin           #+#    #+#              #
#    Updated: 2024/02/13 10:11:50 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FT_PRINTF = libftprintf.a 

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
		srcs/game/init.c \
		srcs/error/exit_error.c \
		srcs/game/move.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Wextra #-Werror

LFLAGS = -L./mlx_linux -lmlx -Ilmlx -lXext -lX11 -L./ft_printf -lftprintf

MLX = mlx_linux/libmlx.a

# MLXL = 	@make -C ./mlx_linux

IFLAGS = -I./

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C ./mlx_linux
	$(MAKE) -C ./ft_printf
	${CC} ${OBJS} ${MLXL} ${LFLAGS} -o $(NAME)
	
%.o:%.c
	${CC} ${IFLAGS} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}
	$(MAKE) -C ft_printf clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY:  all clean fclean re
