/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:57:56 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/26 05:21:18 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(t_data *data, char *str)
{
	char	*new;
	char	*stack;
	int	counter;

	new = check_path(str);
	if (str == NULL)
		return (NULL);
	data->fd = open(str, O_RDONLY);
	if (data->fd == -1)
		return (NULL);
	counter = 0;
	stack = NULL;
	while (data->fd)
	{
		data->info.line = get_next_line(data->fd);
		if (data->info.line == NULL)
			break ;
		if (stack == NULL)
			stack = ft_strdup("");
		stack = ft_strjoin(stack, data->info.line);
		counter++;
	}
	data->map = ft_split(stack, '\n');
	return (data->map);
}
