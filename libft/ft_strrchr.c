/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:23:00 by secker            #+#    #+#             */
/*   Updated: 2022/10/20 11:54:14 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 1;
	while (c > 128)
		c -= 128;
	if (*s == '\0' && c != 0)
		return (NULL);
	while (*s)
	{
		i++;
		s++;
	}
	while (i != 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		i--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
