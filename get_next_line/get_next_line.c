/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:06:17 by secker            #+#    #+#             */
/*   Updated: 2022/11/23 11:41:20 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin2(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_check(char *buffer)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_calloc2((ft_strlen2(buffer) - i + 1), sizeof(char));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	i++;
	k = 0;
	while (buffer[i])
		tmp[k++] = buffer[i++];
	free(buffer);
	return (tmp);
}

char	*ft_nl(char *buffer, int fd)
{
	int		i;
	char	*reading;

	if (!buffer)
		buffer = ft_calloc2(1, 1);
	reading = ft_calloc2(BUFFER_SIZE + 1, 1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, reading, BUFFER_SIZE);
		if (i == -1)
		{
			free(reading);
			return (NULL);
		}
		reading[i] = '\0';
		buffer = ft_free(buffer, reading);
		if (ft_strchr2(reading, '\n'))
			break ;
	}
	free(reading);
	return (buffer);
}

char	*ft_write(char *buffer)
{
	int		k;
	int		j;
	char	*str;

	j = 0;
	k = 0;
	if (!buffer[j])
		return (NULL);
	while (buffer[j] != '\n' && buffer[j])
		j++;
	str = ft_calloc2(j + 2, 1);
	while (buffer[k] != '\n' && buffer[k])
	{
		str[k] = buffer[k];
		k++;
	}
	if (buffer[k] == '\n' && buffer[k])
		str[k++] = '\n';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_nl(buffer, fd);
	if (!buffer)
		return (NULL);
	str = ft_write(buffer);
	buffer = ft_check(buffer);
	return (str);
}
