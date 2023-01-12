/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:05:30 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:08 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_long(long unsigned int n, int i)
{
	char	c;

	if (n > 9)
	{
		i = ft_putnbr_long(n / 10, i);
		i = ft_putnbr_long(n % 10, i);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		i++;
	}
	return (i);
}
