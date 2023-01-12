/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:54:16 by secker            #+#    #+#             */
/*   Updated: 2023/01/12 16:50:49 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}			t_data;

typedef struct s_img
{
	void	*wall;
	void	*gras;
	void	*player;
	void	*open;
	void	*closed;
	void	*dia;
	void	*enemy;
	void	*explosion;
}			t_img;

typedef struct s_vars
{
	t_data	data;
	t_img	img;
	char	**map;
	int		k;
	int		i;
}			t_vars;

int			map_test(char **s);
char		**make_map(char **s);
int			wrong_path(char **s);
void		create_map(char **s);
int			wrong_nubr_c(char **s);
int			wrong_nubr_e(char **s);
int			input(int keycode, t_vars *vars);
int			find_p(char **s);
int			find_p_y(char **s);
void		paint_map(char **s, t_vars *vars);
void		create_images(t_vars *vars);
int			close_x(t_vars *vars);
unsigned int	window_size_y(char **s);
unsigned int	window_size_x(char **s);
char *create_string(t_vars *vars);

#endif