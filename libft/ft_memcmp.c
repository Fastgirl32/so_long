/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:22:41 by secker            #+#    #+#             */
/*   Updated: 2022/10/11 14:08:58 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
		{
			i = *(unsigned char *)s1 - *(unsigned char *)s2;
			if (i > 0)
				i = 1;
			else
				i = -1;
			return (i);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
