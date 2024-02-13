/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:35:48 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 08:16:34 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_str(char *str, char *str2)
{
	free(str);
	free(str2);
	return ;
}

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.player);
	mlx_destroy_image(data->mlx, data->sprite.coll);
	mlx_destroy_image(data->mlx, data->sprite.exit);
	mlx_destroy_image(data->mlx, data->sprite.floor);
	mlx_destroy_image(data->mlx, data->sprite.wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

static int	ft_close_window(t_data *data)
{
	destroy_img(data);
	ft_free_map(data->map);
	free(data->mlx);
	free(data);
	exit (0);
}

static int	check_xpm(t_data *data, int xpm)
{
	if (xpm == 0)
		return (0);
	if (xpm == 2)
		mlx_destroy_image(data->mlx, data->sprite.player);
	if (xpm == 3)
	{
		mlx_destroy_image(data->mlx, data->sprite.player);
		mlx_destroy_image(data->mlx, data->sprite.coll);
	}
	if (xpm == 4)
	{
		mlx_destroy_image(data->mlx, data->sprite.player);
		mlx_destroy_image(data->mlx, data->sprite.coll);
		mlx_destroy_image(data->mlx, data->sprite.exit);
	}
	if (xpm == 5)
	{
		mlx_destroy_image(data->mlx, data->sprite.player);
		mlx_destroy_image(data->mlx, data->sprite.coll);
		mlx_destroy_image(data->mlx, data->sprite.exit);
		mlx_destroy_image(data->mlx, data->sprite.floor);
	}
	return (ft_putstr("Error\nxpm fail\n", 2), 1);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	init_window(data);
	if (check_xpm(data, get_img(data)))
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_map(data->map);
		free(data);
		exit (0);
	}
	init_img(data);
	mlx_hook(data->win, 17, 0, ft_close_window, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	destroy_img(data);
}
