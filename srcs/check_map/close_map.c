/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:59:32 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/03 19:04:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	len = ft_strlen(data->map[0]);
	data->info.col = len;
	while (data->map[i])
	{
		if (i == 0 || i == data->info.line - 1)
		{
			if (!check_close(data->map[i]))
				return (ft_putstr(CLOSE, 2), 0);
		}
		else if (data->map[i][0] != '1' || data->map[i][len - 1] != '1')
			return (ft_putstr(CLOSE, 2), 0);
		i++;
	}
	return (1);
}
