/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:57:51 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 09:05:44 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv(char c, va_list ap)
{
	int	counter;
	int	pt_count;

	pt_count = 0;
	counter = 0;
	if (pt_count < 0)
		return (-1);
	if (c == 's')
		counter += ft_printstr(va_arg(ap, char *));
	else if (c == 'c')
		counter += ft_putchar(va_arg(ap, int));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(ap, int), &pt_count);
	else if (c == 'u')
		counter += ft_unsigned_nb(va_arg(ap, unsigned int), &pt_count);
	else if (c == 'x' || c == 'X')
		counter += ft_print_hex(va_arg(ap, unsigned int), c, &pt_count);
	else if (c == 'p')
		counter += ft_put_p(va_arg(ap, void *));
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += print_conv(str[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
/*int main()
{	
	//int y = ft_printf(0);
	ft_printf("salut les gars");
}*/
