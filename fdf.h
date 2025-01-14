/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:34 by kaara             #+#    #+#             */
/*   Updated: 2025/01/14 23:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"

# define ESC_KEY 65307
# define M_PI 3.14159265358979323846

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	x_i;
	int	y_i;
}	t_coordinate;

typedef struct s_coordinate_data
{
	int				z;
	uint32_t	colar;
	int				render_x;
	int				render_y;
}	t_coordinate_data;

typedef struct s_window_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				window_size_x;
	int				window_size_y;
	void			*img_ptr;
	char			*img_data;
	int				bits_per_pixel; 
	int 			size_line;
	int				endian;
	double			zoom_factor;
}	t_window_data;

typedef struct s_render_size
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
	int	overflow_size_high;
	int	overflow_size_width;
}	t_render_size;

typedef struct s_segment
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_segment;

//make _map.c
t_coordinate_data	***fdf_to_map(char *filename, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);
void				free_map(int error_flag, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);

//make_map_u.c
char				***make_char_map(int fd, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);
t_coordinate_data	***make_map(t_coordinate	*map_size,
						t_window_data	*window_data,
						char ***char_map, t_coordinate_data ***map);
void				free_char_map(t_coordinate *map_size, char ***char_map);

//map_check.c
t_coordinate		*map_check(char *filename, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);

//map_check_u.c
t_coordinate		*get_map_size(int fd, t_coordinate *map_size);

//make_render_map.c
t_coordinate_data	***make_render_map(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);

//make_render_map_u.c
t_coordinate_data	***update_map_to_pixels(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);
t_coordinate_data	*make_render_coordinate(t_coordinate	*map_size,
						double zoom_factor, t_coordinate_data	*map);
t_render_size		*check_render_size(t_coordinate	*map_size,
						t_coordinate_data ***map);
void		get_window_size(t_render_size	*render_size,
						t_window_data	*window_data);
t_coordinate_data	***adjust_negative_coordinates(t_coordinate	*map_size,
						t_render_size	*render_size, t_coordinate_data ***map);

//minilibx_use.c
t_window_data		*make_mlx_window(t_window_data	*window_data);
void				control_mlx_window(t_window_data *window_data);

//minilibx_use_u.c
int					key_hook(int keycode, void *param);
double				get_zoom_factor(t_coordinate *map_size,
						t_coordinate_data ***map);
t_window_data		*window_data_allocate(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map);

//render_map.c
void				render_map(t_coordinate *map_size,
						t_window_data	*window_data, t_coordinate_data ***map);

//render_map_u.c
void				draw_line_bresenham_x(t_coordinate *map_size,
						t_coordinate_data ***map, t_window_data	*window_data);
void				draw_line_bresenham_y(t_coordinate *map_size,
						t_coordinate_data ***map, t_window_data	*window_data);

//fdf_u.c
void				reset_map_index(t_coordinate	*map_size);

#endif