/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:57:48 by secker            #+#    #+#             */
/*   Updated: 2022/10/14 15:54:33 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fill(char *str, int i, int k, int j)
{
	while (i > 0)
	{
		i--;
		k = k / 10;
		str[i] = (k % 10) * j + '0';
	}
	if (j == -1)
		str[0] = '-';
	return (str);
}

int	count(int k)
{
	int	i;

	i = 0;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	k = n;
	j = -1;
	i = count(k);
	if (n > 0)
	{
		j = 1;
		i -= 1;
	}
	str = malloc(i + 2);
	if (!str)
		return (0);
	if (n > 9 || n < 9)
		str = fill(str, i, k, j);
	str[i + 1] = '\0';
	str[i] = (k % 10) * j + '0';
	return (str);
}
