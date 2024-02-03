/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/03 11:49:08 by marvin           ###   ########.fr       */
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
		while (data->map[i])
		{
			j = 0;
			data->map_copy[i] = data->map[i];
			while (data->map[i][j])
			{
				data->map_copy[i][j] = data->map[i][j];
				j++;
			}
			i++;
		}
		free(data);
	}
	return (0);
}
