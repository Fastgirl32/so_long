/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:15:29 by secker            #+#    #+#             */
/*   Updated: 2022/10/14 15:48:18 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*jstr;
	int		i;
	int		j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	jstr = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!jstr)
		return (jstr);
	while (str1[i])
		jstr[j++] = str1[i++];
	i = 0;
	while (str2[i])
		jstr[j++] = str2[i++];
	jstr[j] = '\0';
	return (jstr);
}
