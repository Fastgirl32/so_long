/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_nubr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:43 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:35:06 by secker           ###   ########.fr       */
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
			&& s[i][k] != '0' && s[i][k] != 'G')
		{
			ft_printf("\033[1;31mERROR: There diffrent\033[0m");
			ft_printf("\033[1;31mcharacters than allowed!\033[0m\n");
			return (0);
		}
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
	{
		ft_printf("\033[1;31mERROR: There are more \033[0m");
		ft_printf("\033[1;31mthan 1 Player or no Player!\033[0m\n");
		return (0);
	}
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
