/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:19:16 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:45:01 by secker           ###   ########.fr       */
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
			else if (s[i][k] == 'P')
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
			k++;
		}
		k = 0;
		i++;
	}
}

void	create_map(char **s)
{
	unsigned int	x;
	unsigned int	y;
	t_vars			*vars;
	// t_vars		actualData;
	// vars = &actualData;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->map = s;
	x = window_size_x(s);
	y = window_size_y(s);
	vars->data.mlx = mlx_init();
	vars->data.mlx_win = mlx_new_window(vars->data.mlx, x, y, "so_long");
	create_images(vars);
	mlx_hook(vars->data.mlx_win, 2, 1L << 0, input, &vars);
	mlx_hook(vars->data.mlx_win, 17, 0, input, &vars);
	paint_map(s, vars);
	mlx_loop(vars->data.mlx);
	free(vars);
}
