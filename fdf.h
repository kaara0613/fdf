/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 19:46:39 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# define BUFFER_SIZE 42
# define ESC_KEY 65307

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include "./minilibx-linux/mlx.h"

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_coordinate_data
{
	int	z;
	int	colar;
}	t_coordinate_data;

typedef struct s_window_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window_data;

//minilibx_use.c

t_window_data	*make_mlx_window();
void	control_mlx_window(t_window_data *window_data);

//minilibx_use_u.c
int	key_hook(int keycode, void *param);

//make _map.c
// int	**make_map(int fd, t_coordinate *max);
void	render_map(t_window_data	*window_data);



#endif