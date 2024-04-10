/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:21 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 17:29:23 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_x(t_vars *vars)
{
	mlx_loop_end(vars->data.mlx);
	return (0);
}

void	free_all(t_vars *vars, char **s)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->data.mlx, vars->img.wall);
	mlx_destroy_image(vars->data.mlx, vars->img.explosion);
	mlx_destroy_image(vars->data.mlx, vars->img.dia);
	mlx_destroy_image(vars->data.mlx, vars->img.player);
	mlx_destroy_image(vars->data.mlx, vars->img.gras);
	mlx_destroy_image(vars->data.mlx, vars->img.open);
	mlx_destroy_image(vars->data.mlx, vars->img.closed);
	mlx_destroy_image(vars->data.mlx, vars->img.enemy);
	mlx_destroy_window(vars->data.mlx, vars->data.mlx_win);
	mlx_destroy_display(vars->data.mlx);
	free(vars->data.mlx);
	free(vars);
	while (s[i])
		free(s[i++]);
	free(s);
}
