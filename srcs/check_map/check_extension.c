/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:02:11 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/05 13:02:21 by tpassin          ###   ########.fr       */
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
