/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:25 by kaara             #+#    #+#             */
/*   Updated: 2025/01/14 23:12:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	find_highest_z(t_coordinate *map_size, t_coordinate_data ***map);

int	key_hook(int keycode, void *param)
{
	t_window_data	*window_data;

	window_data = (t_window_data *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(window_data->mlx_ptr, window_data->win_ptr);
		exit(0);
	}
	return (0);
}

double	get_zoom_factor(t_coordinate *map_size, t_coordinate_data ***map)
{
	int		highest_z;
	double	zoom_factor;

	highest_z = find_highest_z(map_size, map);
	if (map_size->y <= highest_z)
		zoom_factor = round((500 / highest_z) * 10) / 10;
	else if (map_size->x <= map_size->y)
		zoom_factor = round((750 / map_size->y) * 10) / 10;
	else
		zoom_factor = round((750 / map_size->x) * 10) / 10;
	return (zoom_factor);
}

static int	find_highest_z(t_coordinate *map_size, t_coordinate_data ***map)
{
	int		highest_z;

	highest_z = 0;
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x - 1)
		{
			if (highest_z < map[map_size->y_i][map_size->x_i]->z)
				highest_z = map[map_size->y_i][map_size->x_i]->z;
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (highest_z);
}

t_window_data	*window_data_allocate(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	window_data = (t_window_data *)malloc(sizeof(t_window_data));
	if (window_data == NULL)
		free_map(1, map_size, window_data, map);
	return (window_data);
}
