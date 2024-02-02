/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/02 20:49:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	t_data *data;
	if (ac != 2)
		return (printf("Error\n2args required\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("faillure malloc\n"), 0);
	int i = 0;
	int j = 0;
	if (init_map(data, av[1]))
	{
		 data->map_copy = map_copy(data, data->map_copy);
		 if (!data->map_copy)
		 	return (0);
		 while (data->map_copy[i])
		 {
			while (data->map_copy[i][j])
			{
				write(1, &data->map_copy[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			j = 0;
			i++;
		 }
		 ft_free_map(data->map_copy);
		free(data);
	}
	return (0);
}
