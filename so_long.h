/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:54:16 by secker            #+#    #+#             */
/*   Updated: 2023/01/13 17:48:08 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
}				t_data;

typedef struct s_img
{
	void		*wall;
	void		*gras;
	void		*player;
	void		*open;
	void		*closed;
	void		*dia;
	void		*enemy;
	void		*explosion;
}				t_img;

typedef struct s_vars
{
	t_data		data;
	t_img		img;
	char		**map;
	int			k;
	int			i;
	int			x;
	int			y;
	char		*won;
	char		*lost;
	char		*gather;
	int			g;
}				t_vars;

int				close_x(t_vars *vars);
int				map_test(char **s);
char			**make_map(char **s, char *argv);
int				wrong_path(char **s);
void			create_map(char **s);
int				wrong_char(char **s);
int				wrong_nubr_p(char **s);
int				wrong_nubr_c(char **s);
int				wrong_nubr_e(char **s);
int				input(int keycode, t_vars *vars);
int				find_p(char **s);
int				find_p_y(char **s);
void			paint_map(char **s, t_vars *vars);
void			create_images(t_vars *vars);
int				close_x(t_vars *vars);
unsigned int	window_size_y(char **s);
unsigned int	window_size_x(char **s);
char			*create_string(t_vars *vars);
void			free_all(t_vars *vars, char **s);
void			player_move_up2(char **s, t_vars *vars, int j, int l);
void			player_move_right2(char **s, t_vars *vars, int j, int l);
void			player_move_down2(char **s, t_vars *vars, int j, int l);
void			player_move_left2(char **s, t_vars *vars, int j, int l);

#endif