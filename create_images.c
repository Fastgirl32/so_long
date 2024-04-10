/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:36:28 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 16:59:58 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_number(t_vars *vars)
{
	int	i;
	int	l;

	i = vars->k - 1;
	l = 0;
	while (i > 0)
	{
		i /= 10;
		l++;
	}
	return (l);
}

char	*create_string(t_vars *vars)
{
	char	*str;
	char	*str2;
	int		i;
	int		l;

	str = "You moved ";
	l = count_number(vars);
	i = vars->k - 1;
	str2 = malloc(l + 1);
	str2[l--] = '\0';
	while (i > 0)
	{
		str2[l--] = (i % 10) + 48;
		i /= 10;
	}
	str = ft_strjoin(str, str2);
	free(str2);
	str2 = " times!";
	str = ft_strjoin(str, str2);
	return (str);
}

void	create_images(t_vars *vars)
{
	int	width;
	int	height;

	height = 48;
	width = 48;
	vars->img.wall = mlx_xpm_file_to_image(vars->data.mlx, "./wall.xpm", &width,
			&height);
	vars->img.dia = mlx_xpm_file_to_image(vars->data.mlx, "./diamond.xpm",
			&width, &height);
	vars->img.gras = mlx_xpm_file_to_image(vars->data.mlx, "./gras.xpm", &width,
			&height);
	vars->img.player = mlx_xpm_file_to_image(vars->data.mlx, "./player.xpm",
			&width, &height);
	vars->img.open = mlx_xpm_file_to_image(vars->data.mlx, "./door_o.xpm",
			&width, &height);
	vars->img.closed = mlx_xpm_file_to_image(vars->data.mlx, "./door_c.xpm",
			&width, &height);
	vars->img.enemy = mlx_xpm_file_to_image(vars->data.mlx, "./enemy.xpm",
			&width, &height);
	vars->img.explosion = mlx_xpm_file_to_image(vars->data.mlx, "./explo.xpm",
			&width, &height);
}
