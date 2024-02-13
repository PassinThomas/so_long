/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:15:12 by tpassin           #+#    #+#             */
/*   Updated: 2024/02/13 09:05:07 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		print_conv(char c, va_list ap);
size_t	ft_print_hex(unsigned int nb, char c, int *ptr);
int		ft_putchar(int c);
int		ft_putnbr(int n, int *ptr);
int		ft_printstr(char *s);
size_t	ft_unsigned_nb(unsigned int nb, int *ptr);
int		ft_printf(const char *str, ...);
int		ft_put_p(void *nbr);
#endif
