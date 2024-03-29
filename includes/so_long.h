/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:00:17 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 08:51:43 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define RECTANGLE	"Error\nmust be a rectangle\n"
# define EMPTY		"Error\nempty line\n"
# define CLOSE		"Error\nmap must be closed\n"
# define UNKNOWN	"Error\nunknown char\n"
# define SPACE		"Error\nspace in map\n"

typedef struct s_sprite
{
	void	*player;
	void	*exit;
	void	*coll;
	void	*wall;
	void	*floor;
}				t_sprite;

typedef struct s_count
{
	int		player;
	int		collect;
	int		line;
	int		col;
	int		exit;
}			t_count;

typedef struct s_pos
{
	int	x;
	int	y;
	int	i;
	int	j;
}			t_pos;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*string;
	char		*stack;
	char		*tmp;
	char		**map;
	int			error;
	int			count;
	t_pos		pos;
	t_count		info;
	t_sprite	sprite;
	int			fd;
}				t_data;

/*parsing*/
char	**get_map(t_data *data, int fd, char **map);
int		check_rectangle(t_data *data);
int		check_wall(t_data *data);
int		check_path(char *str);
int		check_count_info(t_data *data);
int		check_map_contenu(t_data *data);
int		check_all(t_data *data);

/*utils*/
void	ft_putstr(char *s, int fd);
void	ft_free_map(char **map);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
int		ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

/*init data struct*/
void	check_win(t_data *data);
void	init_contenu(t_data *data);
int		init_map(t_data *data, char *str);
void	init_data(t_data *data);
void	free_str(char *str, char *str2);

/*init mlx*/
void	init_img(t_data *data);
void	init_window(t_data *data);
int		get_img(t_data *data);
int		key_hook(int keycode, t_data *data);
void	destroy_img(t_data *data);
void	init_game(t_data *data);

#endif
