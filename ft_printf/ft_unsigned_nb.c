/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:49:38 by tpassin           #+#    #+#             */
/*   Updated: 2023/12/04 18:50:37 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unsigned_nb(unsigned int nb, int *ptr)
{
	if (nb > 9)
		ft_unsigned_nb(nb / 10, ptr);
	*ptr += ft_putchar(nb % 10 + 48);
	return (*ptr);
}
