/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:30 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/05 18:01:39 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_data(t_data *data)
{
	data->tmp = NULL;
	data->stack = NULL;
	data->info.line = 0;
}

static int	error_map(char *stack)
{
	int	empty;
	int	i;

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
			if (i > 0 && ((stack[i - 1] == ' ' || stack[i - 1] == '\t'
						|| stack[i - 1] == '\n'))
				&& ((stack[i] != ' ' && stack[i] != '\t' && stack[i] != '\n')))
				return (ft_putstr(SPACE, 2), 1);
			i++;
		}
	}
	return (0);
}

char	**get_map(t_data *data, int fd, char **map)
{
	init_data(data);
	while (fd)
	{
		data->string = get_next_line(fd);
		if (!data->string)
		{
			if (!data->stack)
				return (ft_putstr("Error\nempty file\n", 2), NULL);
			break ;
		}
		if (!data->stack)
			data->stack = ft_strdup("");
		data->tmp = data->stack;
		data->stack = ft_strjoin(data->tmp, data->string);
		if (error_map(data->string))
			return (free(data->string), free(data->tmp),
				free(data->stack), NULL);
		free(data->string);
		free(data->tmp);
		data->info.line++;
	}
	map = ft_split(data->stack, '\n');
	if (!map)
		return (free(data->stack), NULL);
	return (map);
}

int	check_all(t_data *data)
{
	if (check_rectangle(data) && check_wall(data)
		&& check_map_contenu(data) && check_count_info(data))
		return (1);
	return (0);
}

int	init_map(t_data *data, char *str)
{
	data->map = NULL;
	data->pos.x = 0;
	data->pos.y = 0;
	data->fd = 0;
	if (!check_path(str))
		return (free(data), 0);
	data->fd = open(str, O_RDONLY);
	if (data->fd < 0)
		return (ft_putstr("error\nfail open\n", 2), free(data), 0);
	data->map = get_map(data, data->fd, data->map);
	if (!data->map)
		return (close(data->fd), free(data), 0);
	if (!check_all(data))
		return (close(data->fd), ft_free_map(data->map), free(data), 0);
	check_win(data);
	return (1);
}
