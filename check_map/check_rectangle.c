/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:27:15 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/23 05:59:13 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			ERR_RECTANGLE();
			return (0);
		}
		x++;
		y = 0;
	}
	data->last_line = x;
	return (x);
}
