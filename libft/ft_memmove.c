/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:22:46 by secker            #+#    #+#             */
/*   Updated: 2022/10/14 15:47:10 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if ((char *)dest > (char *)src)
		while (n-- > 0)
			*((char *)dest + n) = *((char *)src + n);
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
