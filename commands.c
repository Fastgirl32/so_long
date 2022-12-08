/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:52:28 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:46:10 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(char **s, int i, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (i == 1 && s[j - 1][l] != 1)
	{
		s[j][l] = '0';
		s[j - 1][l] = 'P';
	}
    else if (i == 2 && s[j][l + 1] != 1)
	{
		s[j][l] = '0';
		s[j][l + 1] = 'P';
	}
    else if (i == 3 && s[j + 1][l] != 1)
	{
		s[j][l] = '0';
		s[j + 1][l] = 'P';
	}
    else if (i == 4 && s[j][l - 1] != 1)
	{
		s[j][l] = '0';
		s[j][l - 1] = 'P';
	}
    paint_map(s, vars);
}

int	input(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
		mlx_destroy_window(vars->data.mlx, vars->data.mlx_win);
	if (keycode == 0xff52 || keycode == 0x0057 || keycode == 0x0077) /*UP*/
		player_move(vars->map, 1, vars);
	if (keycode == 0xff53 || keycode == 0x0044 || keycode == 0x0064) /*RIGHT*/
		player_move(vars->map, 2, vars);
	if (keycode == 0xff54 || keycode == 0x0053 || keycode == 0x0073) /*DOWN*/
		player_move(vars->map, 3, vars);
	if (keycode == 0xff51 || keycode == 0x0041 || keycode == 0x0061) /*LEFT*/
		player_move(vars->map, 4, vars);
	return (0);
}