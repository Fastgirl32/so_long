/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:01:49 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 17:27:10 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up2(char **s, t_vars *vars, int j, int l)
{
	if (s[j - 1][l] == 'G')
	{
		s[j][l] = '0';
		vars->i--;
		ft_printf("You moved %i times!\n", vars->k++);
		ft_printf("\033[1;31mGame Over!\033[0m\n");
	}
	else if (s[j - 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m");
	else
	{
		s[j][l] = '0';
		if (s[j - 1][l] == 'E')
		{
			s[j - 1][l] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;32mYou won the Game!\033[0m\n");
		}
		else
		{
			s[j - 1][l] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
		}
	}
}

void	player_move_right2(char **s, t_vars *vars, int j, int l)
{
	if (s[j][l + 1] == 'G')
	{
		s[j][l] = '0';
		vars->i--;
		ft_printf("You moved %i times!\n", vars->k++);
		ft_printf("\033[1;31mGame Over!\033[0m\n");
	}
	else if (s[j][l + 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n");
	else
	{
		s[j][l] = '0';
		if (s[j][l + 1] == 'E')
		{
			s[j][l + 1] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;32mYou won the Game!\033[0m\n");
		}
		else
		{
			s[j][l + 1] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
		}
	}
}

void	player_move_down2(char **s, t_vars *vars, int j, int l)
{
	if (s[j + 1][l] == 'G')
	{
		s[j][l] = '0';
		vars->i--;
		ft_printf("You moved %i times!\n", vars->k++);
		ft_printf("\033[1;31mGame Over!\033[0m\n");
	}
	else if (s[j + 1][l] == 'E' && wrong_nubr_c(vars->map) != 0)
		ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n");
	else
	{
		s[j][l] = '0';
		if (s[j + 1][l] == 'E')
		{
			s[j + 1][l] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;32mYou won the Game!\033[0m\n");
		}
		else
		{
			s[j + 1][l] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
		}
	}
}

void	player_move_left2(char **s, t_vars *vars, int j, int l)
{
	if (s[j][l - 1] == 'G')
	{
		s[j][l] = '0';
		vars->i--;
		ft_printf("You moved %i times!\n", vars->k++);
		ft_printf("\033[1;31mGame Over!\033[0m\n");
	}
	else if (s[j][l - 1] == 'E' && wrong_nubr_c(vars->map) != 0)
		ft_printf("\033[1;31mDoor closed! Gather all collectables!\033[0m\n");
	else
	{
		s[j][l] = '0';
		if (s[j][l - 1] == 'E')
		{
			s[j][l - 1] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
			ft_printf("\033[1;32mYou won the Game!\033[0m\n");
		}
		else
		{
			s[j][l - 1] = 'P';
			ft_printf("You moved %i times!\n", vars->k++);
		}
	}
}
