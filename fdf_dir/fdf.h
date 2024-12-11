/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 14:02:05 by kaara            ###   ########.fr       */
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
#define ESC_KEY 53

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
void	make_mlx_window(t_window_data *window_data);
void	control_mlx_window(t_window_data *window_data);

//minilibx_use_u.c
void	key_hook(int keycode, void *param);

//make _map.c
int	**make_map(int fd, t_coordinate *max);


#endif