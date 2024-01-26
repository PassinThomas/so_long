/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:43 by tpassin           #+#    #+#             */
/*   Updated: 2024/01/25 03:21:06 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_path(char *str)
{
	char	*extension;

	extension = ft_strchr(str, '.');
	if (extension != NULL && ft_strcmp(extension, ".ber") == 0)
	{
		printf("%s\n", extension);
		printf("good\n");
		return (str);
	}
	printf("Error\nit's not a good path format\n");
	return (NULL);
}
