/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:06:56 by secker            #+#    #+#             */
/*   Updated: 2022/10/20 11:51:24 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	ft_count(char const *s, unsigned int start, size_t len, int i)
{
	while (s[start + i] != '\0' && len > 0)
	{
		len--;
		i++;
	}
	if ((unsigned int)ft_strlen(s) <= start)
		i = 0;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_count(s, start, len, i);
	str = malloc(i + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s[start + i] != '\0' && len > 0)
	{
		str[i] = s[start + i];
		len--;
		i++;
	}
	str[i] = '\0';
	if ((unsigned int)ft_strlen(s) <= start)
		str[0] = '\0';
	return (str);
}
