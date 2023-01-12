/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:36:28 by secker            #+#    #+#             */
/*   Updated: 2023/01/12 16:28:15 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *create_string(t_vars *vars)
{
	char *str;
	char *str2;
	char *str3;
	int i;
	int l;

	i = vars->k - 1;
	l = 0;
	str = "You moved ";
	str3 = " times!";
	while (i > 0)
	{
		i /= 10;
		l++;
	}
	i = vars->k - 1;
	str2 = malloc(l + 1);
	str2[l--]= '\0';
	while(i > 0)
	{
		str2[l--] = (i % 10) + 48;
		i /= 10;
	}
	str = ft_strjoin(str,str2);
	str = ft_strjoin(str,str3);
	free(str2);
	return(str);
}

void	create_images(t_vars *vars)
{
	int img_width;
	int img_height;

	img_height = 48;
	img_width = 48;
	vars->img.wall = mlx_xpm_file_to_image(vars->data.mlx, "./wall.xpm", &img_width, &img_height);
	vars->img.dia = mlx_xpm_file_to_image(vars->data.mlx, "./diamond.xpm", &img_width, &img_height);
	vars->img.gras = mlx_xpm_file_to_image(vars->data.mlx, "./gras.xpm", &img_width, &img_height);
	vars->img.player = mlx_xpm_file_to_image(vars->data.mlx, "./player.xpm", &img_width, &img_height);
	vars->img.open = mlx_xpm_file_to_image(vars->data.mlx, "./door_open.xpm", &img_width, &img_height);
	vars->img.closed = mlx_xpm_file_to_image(vars->data.mlx, "./door_closed.xpm", &img_width, &img_height);
	vars->img.enemy = mlx_xpm_file_to_image(vars->data.mlx, "./enemy.xpm", &img_width, &img_height);
	vars->img.explosion = mlx_xpm_file_to_image(vars->data.mlx, "./explosion.xpm", &img_width, &img_height);
}
