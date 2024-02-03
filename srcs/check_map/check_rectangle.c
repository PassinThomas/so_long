/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:27:15 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/02 16:39:06 by marvin           ###   ########.fr       */
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