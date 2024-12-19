/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 06:03:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"

# define BUFFER_SIZE 42
# define ESC_KEY 65307

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_coordinate_data
{
	int	z;
	int	colar;
	int	render_x;
	int	render_y;
}	t_coordinate_data;

typedef struct s_window_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window_data;

//make _map.c
t_coordinate_data	***fdf_to_map(t_coordinate map_size, char *filename);
void				free_map(t_coordinate	map_size, t_coordinate_data ***map);

//make _map_u.c
char				***make_char_map(t_coordinate	map_size, int fd);
t_coordinate_data	***make_map(t_coordinate	map_size, char ***char_map);
t_coordinate		reset_coordinate(t_coordinate	map_size);
void				free_char_map(t_coordinate map_size, char ***char_map);

//map_check.c
t_coordinate		map_check(char *filename);

//map_check_u.c
t_coordinate		get_map_size(int fd, t_coordinate map_size);

//minilibx_use.c
t_window_data		make_mlx_window(void);
void				control_mlx_window(t_window_data *window_data);

//minilibx_use_u.c
int					key_hook(int keycode, void *param);

//render_map.c
t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_coordinate_data ***map);

//render_map_u.c
t_coordinate_data	*make_render_coordinate(t_coordinate	coordinate_index,
										t_coordinate_data	*map);
// void				render_map(t_window_data	*window_data);


#endif