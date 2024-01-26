/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:00:17 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/26 05:17:11 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 
# include <fcntl.h>

/*# define ERR() write(2, "Error\n", 6)
# define ERR_RECTANGLE() ft_putstr_fd("Error\nLa map doit etre un rectangle\n", 2)
# define ERR_WALL() ft_putstr_fd("Error\nLa map doit etre fermee\n", 2)*/

typedef struct s_count
{
	int		player;
	int		col;
	int		line;
	int		exit;
}			t_count;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_data
{
	char		**map;
	int			*last_line;
	char		*str;
	t_pos		pos_player;
	t_pos		pos_sortie;
	t_count		info;
	int			fd;
}				t_data;

#endif