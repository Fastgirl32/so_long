/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:19:16 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 17:31:12 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	window_size_x(char **s)
{
	int	k;

	k = 0;
	while (s[0][k] != '\n')
		k++;
	return (k * 48);
}

unsigned int	window_size_y(char **s)
{
	int	k;

	k = 0;
	while (s[k])
		k++;
	return (k * 48);
}

void	paint_map2(char **s, t_vars *vars, int i, int k)
{
	if (s[i][k] == 'P')
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.player, (k * 48), (i * 48));
	else if (s[i][k] == 'E')
	{
		if (wrong_nubr_c(s) == 0)
			mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
				vars->img.open, (k * 48), (i * 48));
		else
			mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
				vars->img.closed, (k * 48), (i * 48));
	}
	else if (s[i][k] == '0')
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.gras, (k * 48), (i * 48));
}

void	paint_map(char **s, t_vars *vars)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i][k])
		{
			if (s[i][k] == '1')
				mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
					vars->img.wall, (k * 48), (i * 48));
			else if (s[i][k] == 'C')
				mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
					vars->img.dia, (k * 48), (i * 48));
			else if (s[i][k] == 'G')
				mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
					vars->img.enemy, (k * 48), (i * 48));
			paint_map2(s, vars, i, k);
			k++;
		}
		k = 0;
		i++;
	}
}

/* t_vars		actualData; vars = &actualData; */

void	create_map(char **s)
{
	int				i;
	t_vars			*vars;

	i = 0;
	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->won = "You won the Game!";
	vars->lost = "Game Over!";
	vars->gather = "Door closed! Gather all collectables!";
	vars->map = s;
	vars->k = 1;
	vars->i = 1;
	vars->x = window_size_x(s);
	vars->y = window_size_y(s);
	vars->data.mlx = mlx_init();
	vars->data.mlx_win = mlx_new_window(vars->data.mlx, vars->x, vars->y,
			"so_long");
	create_images(vars);
	paint_map(s, vars);
	mlx_hook(vars->data.mlx_win, 2, 1L << 0, &input, vars);
	mlx_hook(vars->data.mlx_win, 17, 0, &close_x, vars);
	mlx_loop(vars->data.mlx);
	free_all(vars, s);
}
