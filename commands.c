/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:52:28 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 17:51:30 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(char **s, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
		vars->g = mlx_loop_end(vars->data.mlx);
	else if (s[j - 1][l] != '1')
		player_move_up2(s, vars, j, l);
	paint_map(s, vars);
	if (!vars->g && s[j - 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2 - 50,
			vars->y / 2, 0xcc0000, vars->gather);
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
		- 10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0x287233, vars->won);
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.explosion, (l * 48), ((j - 1) * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0xcc0000, vars->lost);
	}
}

void	player_move_right(char **s, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
		mlx_loop_end(vars->data.mlx);
	else if (s[j][l + 1] != '1')
		player_move_right2(s, vars, j, l);
	paint_map(s, vars);
	if (s[j][l + 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2 - 50,
			vars->y / 2, 0xcc0000, vars->gather);
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
		- 10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0x287233, vars->won);
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.explosion, ((l + 1) * 48), (j * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0xcc0000, vars->lost);
	}
}

void	player_move_down(char **s, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
		mlx_loop_end(vars->data.mlx);
	else if (s[j + 1][l] != '1')
		player_move_down2(s, vars, j, l);
	paint_map(s, vars);
	if (s[j + 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2 - 50,
			vars->y / 2, 0xcc0000, vars->gather);
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
		- 10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0x287233, vars->won);
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.explosion, (l * 48), ((j + 1) * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0xcc0000, vars->lost);
	}
}

void	player_move_left(char **s, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
		mlx_loop_end(vars->data.mlx);
	else if (s[j][l - 1] != '1')
		player_move_left2(s, vars, j, l);
	paint_map(s, vars);
	if (s[j][l - 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2 - 50,
			vars->y / 2, 0xcc0000, vars->gather);
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
		- 10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0x287233, vars->won);
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win,
			vars->img.explosion, ((l - 1) * 48), (j * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, vars->x / 2, vars->y
			/ 2, 0xcc0000, vars->lost);
	}
}

/*UP*/
/*RIGHT*/
/*DOWN*/
/*LEFT*/

int	input(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
		mlx_loop_end(vars->data.mlx);
	if (keycode == 0xff52 || keycode == 0x0057 || keycode == 0x0077)
		player_move_up(vars->map, vars);
	if (keycode == 0xff53 || keycode == 0x0044 || keycode == 0x0064)
		player_move_right(vars->map, vars);
	if (keycode == 0xff54 || keycode == 0x0053 || keycode == 0x0073)
		player_move_down(vars->map, vars);
	if (keycode == 0xff51 || keycode == 0x0041 || keycode == 0x0061)
		player_move_left(vars->map, vars);
	return (0);
}
