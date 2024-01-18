/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:59:32 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/18 19:28:40 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	int	x;
	int	y;
	int	len;

	x = 1;
	y = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[x])
	{
		while (data->map[x][y])
			y++;
		if (x > 0 && y != len)
		{
			ERR_RECTANGLE;
			return (0);
		}
		x++;
		y = 0;
	}
	return (x);
}

int	check_wall(t_data *data)
{
}
