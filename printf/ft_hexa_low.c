/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:20:58 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:30:27 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write2(unsigned int i, unsigned int tmp, int j, int k)
{
	int	l;

	l = j;
	while (l >= 0)
	{
		j = l;
		tmp = i;
		while (j != 0)
		{
			tmp /= 16;
			j--;
		}
		if (tmp % 16 < 10)
			k = ft_putchar3(tmp % 16 + '0', k);
		else
			k = ft_putchar3(tmp % 16 - 10 + 'a', k);
		l--;
	}
	return (k);
}

int	ft_hexa_low(unsigned int i, int k)
{
	unsigned int	tmp;
	int				j;

	tmp = i;
	j = 0;
	if (i == 0)
	{
		k = ft_putchar3('0', k);
		return (k);
	}
	while (tmp != 0)
	{
		tmp /= 16;
		j++;
	}
	j--;
	k = ft_write2(i, tmp, j, k);
	return (k);
}
