/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:56:42 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/05 17:35:10 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	*data;

	if (ac != 2)
		return (printf("Error\n2args required\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("faillure malloc\n"), 0);
	if (init_map(data, av[1]))
	{
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 800, 600, "so_long");
		mlx_loop(mlx_ptr);
		mlx_destroy_window(mlx_win, mlx_ptr);
		mlx_ptr = NULL;
		ft_free_map(data->map);
		close(data->fd);
		free(data);
	}
	return (0);
}
