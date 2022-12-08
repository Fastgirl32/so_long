/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:36:28 by secker            #+#    #+#             */
/*   Updated: 2022/12/07 18:41:42 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}