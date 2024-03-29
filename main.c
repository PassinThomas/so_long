/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 08:56:08 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (ft_putstr("Error\n2 args required\n", 2), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr("Error\nfaillure malloc\n", 2), 0);
	if (init_map(data, av[1]))
	{
		data->count = 0;
		init_game(data);
		free(data->mlx);
		ft_free_map(data->map);
		free(data);
	}
	return (0);
}
