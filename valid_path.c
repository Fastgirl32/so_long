/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:57:49 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:13:41 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_path(char **s, int i, int k);

int	find_p(char **s)
{
	int	i;
	int	k;

	i = 1;
	k = 1;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == 'P')
				return (i);
			k++;
		}
		k = 1;
		i++;
	}
	return (0);
}

int	find_p_y(char **s)
{
	int	i;
	int	k;

	i = 1;
	k = 1;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == 'P')
				return (k);
			k++;
		}
		k = 1;
		i++;
	}
	return (0);
}

int	loop_if(char **s, int i, int k, int j)
{
	if (s[i - 1][k] == '0' || s[i - 1][k] == 'C')
	{
		s[i - 1][k] = 'X';
		j = loop_path(s, i - 1, k);
	}
	if (j == 1)
		return (1);
	if (s[i][k + 1] == '0' || s[i][k + 1] == 'C')
	{
		s[i][k + 1] = 'X';
		j = loop_path(s, i, k + 1);
	}
	if (j == 1)
		return (1);
	if (s[i][k - 1] == '0' || s[i][k - 1] == 'C')
	{
		s[i][k - 1] = 'X';
		j = loop_path(s, i, k - 1);
	}
	return (j);
}

int	loop_path(char **s, int i, int k)
{
	int	j;

	j = 0;
	while (s[i][k])
	{
		if (s[i + 1][k] == '0' || s[i + 1][k] == 'C')
		{
			s[i + 1][k] = 'X';
			j = loop_path(s, i + 1, k);
		}
		if (j == 1)
			return (1);
		j = loop_if(s, i, k, j);
		if (s[i + 1][k] == 'E' || s[i - 1][k] == 'E' || s[i][k - 1] == 'E'
			|| s[i][k + 1] == 'E' || j == 1)
			return (1);
		return (0);
	}
	return (0);
}

int	wrong_path(char **s)
{
	int	i;
	int	k;
	int	j;

	i = find_p(s);
	k = find_p_y(s);
	j = loop_path(s, i, k);
	if (j == 1)
		return (1);
	ft_printf("\033[1;31mERROR: There is no valid path!\033[0m\n");
	return (0);
}
