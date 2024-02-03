/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/03 18:37:17 by marvin           ###   ########.fr       */
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
		map_cp = map_copy(map_cp, data);
		get_position(data);
		if (!(check_win(map_cp, data)))
		{
			ft_free_map(map_cp);
			ft_free_map(data->map);
			close(data->fd);
			free(data);
		}
		close(data->fd);
		free(data);
	}
	return (0);
}
