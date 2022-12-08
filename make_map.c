/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:55:54 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:37:39 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_map(char **s)
{
	char	*str;
	int		i;
    int     fd;

	i = 0;
	fd = open("map1.txt", O_RDONLY);
	if(fd == 0)
		return(0);
	str = get_next_line(fd);
	while (str)
	{
		i += ft_strlen(str);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	s = malloc(i);
	i = 0;
	fd = open("map1.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		s[i] = str;
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (s);
}