/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:48:13 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/12 23:00:04 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->info.col * 64,
			data->info.line * 64, "so_long");
	return ;
}

int	get_img(t_data *data)
{
	int	i;

	data->sprite.player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm",
			&i, &i);
	if (!data->sprite.player)
		return (1);
	data->sprite.coll = mlx_xpm_file_to_image(data->mlx, "./img/coll.xpm",
			&i, &i);
	if (!data->sprite.coll)
		return (2);
	data->sprite.exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm",
			&i, &i);
	if (!data->sprite.exit)
		return (3);
	data->sprite.floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&i, &i);
	if (!data->sprite.floor)
		return (4);
	data->sprite.wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm",
			&i, &i);
	if (!data->sprite.wall)
		return (5);
	else
		return (0);
}

static void	put_img(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.player,
			j * 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.coll,
			j * 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.exit,
			j * 64, i * 64);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.floor,
			j * 64, i * 64);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.wall,
			j * 64, i * 64);
}

void	init_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_img(data, i, j);
			j++;
		}
		i++;
	}
}
