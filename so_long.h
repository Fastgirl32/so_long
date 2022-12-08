/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:54:16 by secker            #+#    #+#             */
/*   Updated: 2022/12/08 16:44:59 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}			t_data;

typedef struct s_keys
{
}			t_keys;

typedef struct s_img
{
	void	*wall;
	void	*gras;
	void	*player;
	void	*open;
	void	*closed;
	void	*dia;
}			t_img;

typedef struct s_vars
{
	t_data	data;
	t_img	img;
	t_keys	keys;
	char ** map;
}			t_vars;

int			map_test(char **s);
char		**make_map(char **s);
int			wrong_path(char **s);
void		create_map(char **s);
int			wrong_nubr_c(char **s);
int			input(int keycode, t_vars *vars);
int			find_p(char **s);
int			find_p_y(char **s);
void		paint_map(char **s, t_vars *vars);
void		create_images(t_vars *vars);

#endif