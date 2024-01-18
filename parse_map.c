/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:59:32 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/18 17:58:59 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rectangle(char **map)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	len = ft_strlen(map[0]);
	while (map[x])
	{
		while (map[x][y])
			y++;
		if (x > 0 && y != len)
		{
			write(2, "Error", 5);
			return (0);
		}
		x++;
		y = 0;
	}
	return (1);
}

int	check_wall(char **map)
{

}
