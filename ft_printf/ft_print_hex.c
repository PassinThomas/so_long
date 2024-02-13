/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:33:50 by tpassin           #+#    #+#             */
/*   Updated: 2023/12/04 18:51:18 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex(unsigned int nb, char c, int *ptr)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb < 16)
		*ptr += ft_putchar(base[nb]);
	else
	{
		ft_print_hex(nb / 16, c, ptr);
		*ptr += ft_putchar(base[nb % 16]);
	}
	return (*ptr);
}
