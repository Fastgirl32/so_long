/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:05:30 by secker            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:09 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int n, int i)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		i = ft_putnbr(-n, i) + 1;
	}
	else if (n > 9)
	{
		i = ft_putnbr(n / 10, i);
		i = ft_putnbr(n % 10, i);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		i++;
	}
	return (i);
}