/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:50:36 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:04 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_low2(long unsigned int i, int k)
{
	if (i % 16 < 10)
		k = ft_putchar3(i % 16 + '0', k);
	else
		k = ft_putchar3(i % 16 - 10 + 'a', k);
	return (k);
}

int	loop(void *s, long unsigned int tmp, int i, int k)
{
	int	j;

	while (i >= 0)
	{
		j = i;
		while (j != 0)
		{
			tmp /= 16;
			j--;
		}
		k = ft_hexa_low2(tmp, k);
		i -= 1;
		tmp = (long unsigned int)s;
	}
	return (k);
}

int	ft_pointer(void *s, int k)
{
	long unsigned int	tmp;
	int					i;

	tmp = (long unsigned int)s;
	if (tmp == 0)
	{
		write(1, "(nil)", 5);
		return (k + 5);
	}
	write(1, "0x", 2);
	k += 2;
	i = 0;
	while (tmp != 0)
	{
		tmp /= 16;
		i++;
	}
	i--;
	tmp = (long unsigned int)s;
	k = loop(s, tmp, i, k);
	return (k);
}
