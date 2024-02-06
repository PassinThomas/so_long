/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:09:02 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/06 12:38:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**map_copy(t_data *data)
{
	char	**map;
	int		i;
	int		len;

	i = 0;
	len = data->info.line;
	map = (char **)malloc(sizeof(char *) * (len + 2));
	if (!map)
		return (NULL);
	while (i < len)
	{
		map[i] = strdup(data->map[i]);
		if (!map[i])
			return (ft_free_map(map), NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->info.line || y < 0 || y >= data->info.col
		|| map[x][y] == 'x')
		return ;
	if (map[x][y] == '1')
		return ;
	map[x][y] = 'x';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

static int	valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == 'P')
			{
				ft_free_map(map);
				return (ft_putstr("Element non atteignable\n", 2), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_win(t_data *data)
{
	char	**map;

	map = NULL;
	map = map_copy(data);
	//printf("%c\n", map[data->pos.x][data->pos.y]);
	flood_fill(map, data->pos.x, data->pos.y, data);
	if (valid_map(map))
	{
		ft_free_map(map);
		ft_putstr("win\n", 1);
	}
	return ;
}
