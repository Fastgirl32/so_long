/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:55:54 by secker            #+#    #+#             */
/*   Updated: 2023/01/12 16:51:11 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_map(char **s)
{
	char	*str;
	char	*str2;
	int		i;
    int     fd;
	int k;

	i = 0;
	k = 0;
	fd = open("map1.ber", O_RDONLY);
	if(fd == 0)
		return(0);
	str = get_next_line(fd);
	while (str)
	{
		i += ft_strlen(str);
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	s = malloc(i);
	i = 0;
	fd = open("map1.ber", O_RDONLY);
	str2 = get_next_line(fd);
	while (str2)
	{
		s[i] = str2;
		i++;
		str2 = get_next_line(fd);
	}
	close(fd);
	return (s);
}