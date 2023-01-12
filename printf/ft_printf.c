/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:21 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:29:11 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_percent(const char *s, va_list print, int i)
{
	if (*s == '%')
		i = ft_putchar3(*s, i);
	else if (*s == 'c')
		i = ft_putchar3(va_arg(print, int), i);
	else if (*s == 's')
		i = ft_putstr3(va_arg(print, char *), i);
	else if (*s == 'p')
		i = ft_pointer(va_arg(print, void *), i);
	else if (*s == 'd')
		i = ft_putnbr(va_arg(print, int), i);
	else if (*s == 'i')
		i = ft_putnbr(va_arg(print, int), i);
	else if (*s == 'u')
		i = ft_putnbr_long(va_arg(print, long unsigned int), i);
	else if (*s == 'x')
		i = ft_hexa_low(va_arg(print, unsigned int), i);
	else if (*s == 'X')
		i = ft_hexa_up(va_arg(print, unsigned int), i);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	print;

	i = 0;
	va_start(print, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			i = ft_percent(s, print, i);
		}
		else
			i = ft_putchar3(*s, i);
		s++;
	}
	va_end(print);
	return (i);
}
