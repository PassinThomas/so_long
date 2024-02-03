/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/03 12:53:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	int i = 0;
	int j;

	t_data *data;
	if (ac != 2)
		return (printf("Error\n2args required\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("faillure malloc\n"), 0);
	if (init_map(data, av[1]))
	{
		data->map_copy = map_copy(data);
		get_position(data);
		printf("%d\n%d\n", data->pos.y, data->pos.x);
		/*while (data->map_copy[i])
		{
			j = 0;
			while (data->map_copy[i][j])
				write(1, &data->map_copy[i][j++], 1);
			write(1, "\n", 1);
			i++;
		}*/
		ft_free_map(data->map_copy);
		ft_free_map(data->map);
		close(data->fd);
		free(data);
	}
	return (0);
}
