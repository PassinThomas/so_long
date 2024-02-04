/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/04 08:46:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	int i = 0;
	int j;
	char **map_cp;

	t_data *data;
	if (ac != 2)
		return (printf("Error\n2args required\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("faillure malloc\n"), 0);
	map_cp = NULL;
	if (init_map(data, av[1]))
	{
		map_cp = map_copy(data);
		if (map_cp)
		{
			while (map_cp[i])
			{
				j = 0;
				while (map_cp[i][j])
				{
					if (map_cp[i][j] == 'P')
					{
						data->pos.x = i;
						data->pos.y = j;
					}
					j++;
				}
				i++;
			}
		}
		check_win(map_cp, data);
		ft_free_map(data->map);
		close(data->fd);
		free(data);
		return (0);
	}
	close(data->fd);
	free(data);
	return (0);
}
