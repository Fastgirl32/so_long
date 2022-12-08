/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:22:57 by secker            #+#    #+#             */
/*   Updated: 2022/10/13 11:15:42 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	loop(const char *big, const char *little, int k, size_t len)
{
	if ((int)len > 0)
		len++;
	while (*big == *little && *big != '\0' && len != 0)
	{
		little++;
		big++;
		k++;
		len--;
	}
	if (*little == '\0' && len != 0)
		return (k);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	k;

	k = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (*big != '\0' && len != 0)
	{
		k = loop(big, little, k, len);
		if (k != 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
