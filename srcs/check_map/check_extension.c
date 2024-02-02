/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:43 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/02 15:47:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_path(char *str)
{
	char	*extension;

	extension = ft_strchr(str, '.');
	if (extension != NULL && strcmp(extension, ".ber") == 0)
		return (1);
	printf("Error\nbad extension\n");
	return (0);
}
