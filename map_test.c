/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:19:22 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:38:23 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrong_char(char **s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i][k] != 'P' && s[i][k] != 'C' && s[i][k] != 'E' && s[i][k] != '1'
			&& s[i][k] != '0')
			return (0);
		k++;
		if (!s[i][k + 1])
		{
			i++;
			k = 0;
		}
	}
	return (1);
}

int	wrong_nubr_p(char **s)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == 'P')
				j++;
			k++;
		}
		i++;
		k = 0;
	}
	if (j > 1 || j == 0)
		return (0);
	return (1);
}

int	wrong_nubr_c(char **s)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == 'C')
				j++;
			k++;
		}
		i++;
		k = 0;
	}
	if (j == 0)
		return (0);
	return (1);
}

int	wrong_nubr_e(char **s)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == 'E')
				j++;
			k++;
		}
		k = 0;
		i++;
	}
	if (j > 1 || j == 0)
		return (0);
	return (1);
}

int	wrong_border(char **s)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (s[0][k + 1])
	{
		if (s[0][k] != '1')
			return (0);
		k++;
	}
	k = 0;
	while (s[i + 1])
	{
		k = ft_strlen(s[i]) - 2;
		if (s[i][0] != '1' || s[i][k] != '1')
			return (0);
		i++;
	}
	k = 0;
	while (s[i][k + 1])
	{
		if (s[i][k] != '1')
			return (0);
		k++;
	}
	return (1);
}

int	wrong_square(char **s)
{
	int	i;
	int	k;
	int	j;

	i = 1;
	while (s[i + 1])
	{
		k = ft_strlen(s[i - 1]);
		j = ft_strlen(s[i]);
		if (k != j)
			return (0);
		i++;
	}
	return (1);
}

int	map_test(char **s)
{
	int	i;

	i = 1;
	if (s[0][0] == '\0')
		i = 0;
	if (i != 0)
		i = wrong_square(s);
	if (i != 0)
		i = wrong_char(s);
	if (i != 0)
		i = wrong_border(s);
	if (i != 0)
		i = wrong_nubr_p(s);
	if (i != 0)
		i = wrong_nubr_c(s);
	if (i != 0)
		i = wrong_nubr_e(s);
	if (i != 0)
		i = wrong_path(s);
	if (i == 0)
	{
		free(s);
		return (0);
	}
	return (1);
}
