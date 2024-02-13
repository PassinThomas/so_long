/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:48:50 by tpassin           #+#    #+#             */
/*   Updated: 2023/12/08 10:35:02 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *ptr)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		*ptr += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, ptr);
	*ptr += ft_putchar(nb % 10 + 48);
	return (*ptr);
}
