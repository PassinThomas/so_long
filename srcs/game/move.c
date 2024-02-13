/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:01:45 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 04:15:31 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(int keycode, t_data *data)
{
	if (keycode == 65362 || keycode == 119)
	{
		if (data->map[data->pos.x - 1][data->pos.y] != '1')
		{
			if (data->map[data->pos.x - 1][data->pos.y] == 'C')
				data->info.collect--;
			if (data->map[data->pos.x - 1][data->pos.y] != 'E')
			{
				data->map[data->pos.x--][data->pos.y] = '0';
				data->count++;
				ft_printf("Moves: %d\n", data->count);
			}
			if (data->map[data->pos.x - 1][data->pos.y] == 'E'
				&& data->info.collect == 0)
			{
				data->count++;
				ft_printf("Moves: %d\n", data->count);
				mlx_loop_end(data->mlx);
				ft_printf("You have Won\n");
			}
		}
	}
	data->map[data->pos.x][data->pos.y] = 'P';
	init_img(data);
}

void	move_down(int keycode, t_data *data)
{
	if (keycode == 65364 || keycode == 115)
	{
		if (data->map[data->pos.x + 1][data->pos.y] != '1')
		{
			if (data->map[data->pos.x + 1][data->pos.y] == 'C')
				data->info.collect--;
			if (data->map[data->pos.x + 1][data->pos.y] != 'E')
			{
				data->map[data->pos.x++][data->pos.y] = '0';
				data->count++;
				ft_printf("Moves: %d\n", data->count);
			}
			if (data->map[data->pos.x + 1][data->pos.y] == 'E'
					&& data->info.collect == 0)
			{
				data->count++;
				ft_printf("Moves: %d\n", data->count);
				mlx_loop_end(data->mlx);
				ft_printf("You have Won\n");
			}
		}
	}
	data->map[data->pos.x][data->pos.y] = 'P';
	init_img(data);
}

void	move_left(int keycode, t_data *data)
{
	if (keycode == 65361 || keycode == 97)
	{
		if (data->map[data->pos.x][data->pos.y - 1] != '1')
		{
			if (data->map[data->pos.x][data->pos.y - 1] == 'C')
				data->info.collect--;
			if (data->map[data->pos.x][data->pos.y - 1] != 'E')
			{
				data->map[data->pos.x][data->pos.y--] = '0';
				data->count++;
				ft_printf("Moves: %d\n", data->count);
			}
			if (data->map[data->pos.x][data->pos.y - 1] == 'E'
					&& data->info.collect == 0)
			{
				data->count++;
				ft_printf("Moves: %d\n", data->count);
				mlx_loop_end(data->mlx);
				ft_printf("You have Won\n");
			}
		}
	}
	data->map[data->pos.x][data->pos.y] = 'P';
	init_img(data);
}

void	move_right(int keycode, t_data *data)
{
	if (keycode == 65363 || keycode == 100)
	{
		if (data->map[data->pos.x][data->pos.y + 1] != '1')
		{
			if (data->map[data->pos.x][data->pos.y + 1] == 'C')
				data->info.collect--;
			if (data->map[data->pos.x][data->pos.y + 1] != 'E')
			{
				data->map[data->pos.x][data->pos.y++] = '0';
				data->count++;
				ft_printf("Moves: %d\n", data->count);
			}
			if (data->map[data->pos.x][data->pos.y + 1] == 'E'
					&& data->info.collect == 0)
			{
				data->count++;
				ft_printf("Moves: %d\n", data->count);
				mlx_loop_end(data->mlx);
				ft_printf("You have Won\n");
			}
		}
	}
	data->map[data->pos.x][data->pos.y] = 'P';
	init_img(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		return (mlx_loop_end(data->mlx), 0);
	else if (keycode == 115 || keycode == 65364)
		move_down(keycode, data);
	else if (keycode == 119 || keycode == 65362)
		move_up(keycode, data);
	else if (keycode == 97 || keycode == 65361)
		move_left(keycode, data);
	else if (keycode == 100 || keycode == 65363)
		move_right(keycode, data);
	return (0);
}
