/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:19:22 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:34:59 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrong_border2(char **s, int i, int k)
{
	if (s[i][k] != '1')
	{
		ft_printf("\033[1;31mERROR: The Map is \033[0m");
		ft_printf("\033[1;31mnot surrounded by walls!\033[0m\n");
		return (0);
	}
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
		if (wrong_border2(s, 0, k) == 0)
			return (0);
		k++;
	}
	while (s[i + 1])
	{
		k = ft_strlen(s[i++]) - 2;
		if (wrong_border2(s, i, 0) == 0 || wrong_border2(s, i, k) == 0)
			return (0);
	}
	k = 0;
	while (s[i][k + 1])
	{
		if (wrong_border2(s, i, k) == 0)
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
		{
			ft_printf("\033[1;31mERROR: The Map is not a rectangle!\033[0m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	other_tests(char **s)
{
	int	i;

	i = 1;
	if (i != 0)
		i = wrong_nubr_c(s);
	if (i == 0)
		ft_printf("\033[1;31mERROR: There are no collectables!\033[0m\n");
	if (i != 0)
		i = wrong_nubr_e(s);
	if (i == 0)
	{
		ft_printf("\033[1;31mERROR: There are more \033[0m");
		ft_printf("\033[1;31mthan 1 Exits or no Exits!\033[0m\n");
	}
	if (i != 0)
		i = wrong_path(s);
	return (i);
}

int	map_test(char **s)
{
	int	i;
	int	k;

	k = 0;
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
		i = other_tests(s);
	if (i == 0)
		return (0);
	return (1);
}
