/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:44:29 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 09:06:59 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (ft_printstr("(null)"));
	}
	while (s && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	if (i < 0)
		return (-1);
	return (i);
}
