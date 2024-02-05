/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:27:15 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/05 13:52:46 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_rectangle(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		while (data->map[i][j])
			j++;
		if (i > 0 && j != len)
		{
			ft_putstr(RECTANGLE, 2);
			return (0);
		}
		i++;
		j = 0;
	}
	if (i < 2 || len < 2)
		return (ft_putstr(RECTANGLE, 2), 0);
	return (1);
}

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
