/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:03:34 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/05 18:00:10 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_contenu(t_data *data)
{
	data->info.player = 0;
	data->info.collect = 0;
	data->info.exit = 0;
	data->pos.x = 0;
	data->pos.y = 0;
	data->pos.i = 0;
	data->pos.j = 0;
}

static int	cut_ft(t_data *data)
{
	if (data->map[data->pos.i][data->pos.j] != '1'
				&& data->map[data->pos.i][data->pos.j] != '0'
				&& data->map[data->pos.i][data->pos.j] != 'C'
				&& data->map[data->pos.i][data->pos.j] != 'P'
				&& data->map[data->pos.i][data->pos.j] != 'E')
		return (1);
	return (0);
}

int	check_map_contenu(t_data *data)
{
	init_contenu(data);
	while (data->map[data->pos.i])
	{
		while (data->map[data->pos.i][data->pos.j])
		{
			if (cut_ft(data))
				return (ft_putstr(UNKNOWN, 2), 0);
			else if (data->map[data->pos.i][data->pos.j] == 'P')
			{
				data->pos.x = data->pos.i;
				data->pos.y = data->pos.j;
				data->info.player++;
			}
			else if (data->map[data->pos.i][data->pos.j] == 'C')
				data->info.collect++;
			else if (data->map[data->pos.i][data->pos.j] == 'E')
				data->info.exit++;
			data->pos.j++;
		}
		data->pos.i++;
		data->pos.j = 0;
	}
	return (1);
}

int	check_count_info(t_data *data)
{
	if (data->info.player != 1)
		return (ft_putstr("Error\n1 player required\n", 2), 0);
	else if (data->info.collect < 1)
		return (ft_putstr("Error\nnot collectible\n", 2), 0);
	else if (data->info.exit != 1)
		return (ft_putstr("Error\nonly 1 exit required\n", 2), 0);
	ft_putstr("MAP OK\n", 1);
	return (1);
}
