/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:52:28 by secker            #+#    #+#             */
/*   Updated: 2023/01/12 17:13:11 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_x(t_vars *vars)
{
	mlx_loop_end(vars->data.mlx);
	return (0);
}

void	player_move_up(char **s, int i, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
	{
		mlx_loop_end(vars->data.mlx);
	}
	else if (i == 1 && s[j - 1][l] != '1')
	{
		if (s[j - 1][l] == 'G')
		{
			s[j][l] = '0';
			vars->i--;
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;31mGame Over!\033[0m\n");
		}
		else if (s[j - 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		{
			ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m");
		}
		else
		{
			s[j][l] = '0';
			if (s[j - 1][l] == 'E')
			{
				s[j - 1][l] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
				ft_printf("\033[1;32mYou won the Game!\033[0m\n", 1);
			}
			else
			{
				s[j - 1][l] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
			}
		}
	}
	paint_map(s, vars);
	if (s[j - 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2- 50, window_size_y(s)/2, 0xcc0000, "Door closed! Gather all collectables!");
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)-10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0x287233, "You won the Game!");
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win, vars->img.explosion, (l * 48), ((j - 1) * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0xcc0000, "Game Over!");
	}
}

void	player_move_right(char **s, int i, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
	{
		mlx_loop_end(vars->data.mlx);
	}
	else if (i == 2 && s[j][l + 1] != '1')
	{
		if (s[j][l + 1] == 'G')
		{
			s[j][l] = '0';
			vars->i--;
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;31mGame Over!\033[0m\n");
		}
		else if (s[j][l + 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		{
			ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n",
						1);
		}
		else
		{
			s[j][l] = '0';
			if (s[j][l + 1] == 'E')
			{
				s[j][l + 1] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
				ft_printf("\033[1;32mYou won the Game!\033[0m\n", 1);
			}
			else
			{
				s[j][l + 1] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
			}
		}
	}
	paint_map(s, vars);
	if (s[j][l + 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2- 50, window_size_y(s)/2, 0xcc0000, "Door closed! Gather all collectables!");
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)-10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0x287233, "You won the Game!");
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win, vars->img.explosion, ((l + 1) * 48), (j * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0xcc0000, "Game Over!");
	}
}

void	player_move_down(char **s, int i, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
	{
		mlx_loop_end(vars->data.mlx);
	}
	else if (i == 3 && s[j + 1][l] != '1')
	{
		if (s[j + 1][l] == 'G')
		{
			s[j][l] = '0';
			vars->i--;
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;31mGame Over!\033[0m\n");
		}
		else if (s[j + 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		{
			ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n",
						1);
		}
		else
		{
			s[j][l] = '0';
			if (s[j + 1][l] == 'E')
			{
				s[j + 1][l] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
				ft_printf("\033[1;32mYou won the Game!\033[0m\n", 1);
			}
			else
			{
				s[j + 1][l] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
			}
		}
	}
	paint_map(s, vars);
	if (s[j + 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2- 50, window_size_y(s)/2, 0xcc0000, "Door closed! Gather all collectables!");
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)-10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0x287233, "You won the Game!");
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win, vars->img.explosion, (l * 48), ((j + 1) * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0xcc0000, "Game Over!");
	}
}

void	player_move_left(char **s, int i, t_vars *vars)
{
	int	j;
	int	l;

	j = find_p(s);
	l = find_p_y(s);
	if (wrong_nubr_e(vars->map) == 0 || vars->i == 0)
	{
		mlx_loop_end(vars->data.mlx);
	}
	else if (i == 4 && s[j][l - 1] != '1')
	{
		if (s[j][l - 1] == 'G')
		{
			s[j][l] = '0';
			vars->i--;
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;31mGame Over!\033[0m\n");
		}
		else if (s[j][l - 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		{
			ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n",
						1);
		}
		else
		{
			s[j][l] = '0';
			if (s[j][l - 1] == 'E')
			{
				s[j][l - 1] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
				ft_printf("\033[1;32mYou won the Game!\033[0m\n", 1);
			}
			else
			{
				s[j][l - 1] = 'P';
				ft_printf("You moved %i times!\n", vars->k++);
			}
		}
	}
	paint_map(s, vars);
	if (s[j][l - 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2 - 50, window_size_y(s)/2, 0xcc0000, "Door closed! Gather all collectables!");
	mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)-10, 31, create_string(vars));
	if (wrong_nubr_e(vars->map) == 0)
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0x287233, "You won the Game!");
	if (vars->i == 0)
	{
		mlx_put_image_to_window(vars->data.mlx, vars->data.mlx_win, vars->img.explosion, ((l - 1) * 48), (j * 48));
		mlx_string_put(vars->data.mlx, vars->data.mlx_win, window_size_x(s)/2, window_size_y(s)/2, 0xcc0000, "Game Over!");
	}
}

int	input(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
		mlx_loop_end(vars->data.mlx);
	if (keycode == 0xff52 || keycode == 0x0057 || keycode == 0x0077) /*UP*/
		player_move_up(vars->map, 1, vars);
	if (keycode == 0xff53 || keycode == 0x0044 || keycode == 0x0064) /*RIGHT*/
		player_move_right(vars->map, 2, vars);
	if (keycode == 0xff54 || keycode == 0x0053 || keycode == 0x0073) /*DOWN*/
		player_move_down(vars->map, 3, vars);
	if (keycode == 0xff51 || keycode == 0x0041 || keycode == 0x0061) /*LEFT*/
		player_move_left(vars->map, 4, vars);
	return (0);
}