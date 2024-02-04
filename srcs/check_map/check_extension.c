/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:43 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/04 10:37:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_path(char *str)
{
	char	*extension;

	extension = ft_strchr(str, '.');
	if (extension != NULL && ft_strcmp(extension, ".ber") == 0)
		return (1);
	ft_putstr("Error\nbad extension\n", 2);
	return (0);
}
