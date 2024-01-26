/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:59:32 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/24 06:20:03 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_close(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (data->map[i])
	{
		if (i == 0 || i == data->last_line)
		{
			if (!check_close(data->map[i]))
			{
				ERR_WALL();
				return (0);
			}
		}
		else if (data->map[i][0] || data->map[i][len - 1])
		{
			if (data->map[i][0] || data->map[i][len - 1])
			{

			}
		}
		i++;
	}
}
