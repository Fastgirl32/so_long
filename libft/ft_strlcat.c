/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:05:08 by secker            #+#    #+#             */
/*   Updated: 2022/10/14 15:47:40 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;
	size_t	t;

	if (!dest && !src)
		return (0);
	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	t = dlen;
	if (!size || size <= dlen)
		return (slen + size);
	while (src[i] && i < size - dlen - 1)
	{
		dest[t] = src[i];
		i++;
		t++;
	}
	dest[t] = '\0';
	return (slen + dlen);
}
