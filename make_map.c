/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:55:54 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:40:00 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *argv)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		i += ft_strlen(str);
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**make_map(char **s, char *argv)
{
	char	*str2;
	int		i;
	int		fd;

	i = count_lines(argv);
	s = malloc(i);
	i = 0;
	fd = open(argv, O_RDONLY);
	str2 = get_next_line(fd);
	while (str2)
	{
		s[i] = str2;
		i++;
		str2 = get_next_line(fd);
	}
	s[i] = NULL;
	close(fd);
	return (s);
}
