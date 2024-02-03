/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:57:56 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/02 16:37:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void init_get_map(t_data *data)
{
	data->tmp = NULL;
	data->stack = NULL;
	data->info.line = 0;
}

static int error_map(char *stack)
{
	int empty;
	int i;

	i = 0;
	empty = 0;
	while (stack[i])
	{
		if (i == 0 && stack[i] == '\n')
			return (ft_putstr(EMPTY, 2), 1);
		if (stack[i] == ' ' || stack[i] == '\t' || stack[i] == '\n')
		{
			empty = 1;
			i++;
		}
		else
		{
			if ( i > 0 && (stack[i - 1] == ' ' || stack[i - 1] == '\t'
			|| stack[i - 1] == '\n')
			&& (stack[i] != ' ' && stack[i] && '\t' && stack[i] != '\n'))
			{
				return (ft_putstr(SPACE, 2), 1);
			}
			i++;
		}
	}
	return (0);
}

char	**get_map(t_data *data, int fd, char **map)
{
	init_get_map(data);
	while (fd)
	{
		data->string = get_next_line(fd);
		if (!data->string)
		{
			if (!data->stack)
				return (ft_putstr("Error\nempty file\n", 2), NULL);
			break;
		}
		if (!data->stack)
			data->stack = ft_strdup("");
		data->tmp = data->stack;
		data->stack = ft_strjoin(data->tmp, data->string);
		if (error_map(data->string))
			return (free(data->string),free(data->tmp), free(data->stack), NULL);
		free(data->string);
		free(data->tmp);
		data->info.line++;
	}
	map = ft_split(data->stack, '\n');
	if (!map)
		return (free(data->stack), NULL);
	return (map);
}