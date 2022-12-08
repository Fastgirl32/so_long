/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:12 by secker            #+#    #+#             */
/*   Updated: 2022/10/14 15:47:29 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (k <= i)
	{
		str[k] = s[k];
		k++;
	}
	return (str);
}
