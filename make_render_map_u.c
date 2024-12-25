/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:57 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 15:27:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				render_size_reset(t_render_size *render_size);
static t_render_size	*update_min_max(t_render_size	*render_size,
							t_coordinate	*map_size,
							t_coordinate_data	***map);

t_coordinate_data	***update_map_to_pixels(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			map[map_size->y_i][map_size->x_i]
				= make_render_coordinate
				(map_size, window_data->zoom_factor,
					map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (map);
}

t_coordinate_data	*make_render_coordinate(t_coordinate	*map_size,
						double zoom_factor, t_coordinate_data	*map)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = M_PI / 6;
	temp_x = (map_size->x_i - map_size->y_i) * cos(angle);
	temp_y = (map_size->x_i + map_size->y_i)
		* sin(angle) - map->z;
	map->render_x = (int)(round(temp_x * zoom_factor));
	map->render_y = (int)(round(temp_y * zoom_factor));
	return (map);
}

t_render_size	*check_render_size(t_coordinate	*map_size,
						t_window_data *window_data, t_coordinate_data ***map)
{
	t_render_size	*render_size;

	reset_map_index(map_size);
	render_size = (t_render_size *)malloc(sizeof(t_render_size));
	if (map == NULL)
		free_map(1, map_size, window_data, map);
	render_size_reset(render_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			update_min_max(render_size, map_size, map);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (render_size);
}

static t_render_size	*update_min_max(t_render_size	*render_size,
					t_coordinate	*map_size, t_coordinate_data	***map)
{
	if (render_size->x_min > map[map_size->y_i][map_size->x_i]->render_x)
		render_size->x_min = map[map_size->y_i][map_size->x_i]->render_x;
	if (render_size->x_max < map[map_size->y_i][map_size->x_i]->render_x)
		render_size->x_max = map[map_size->y_i][map_size->x_i]->render_x;
	if (render_size->y_min > map[map_size->y_i][map_size->x_i]->render_y)
		render_size->y_min = map[map_size->y_i][map_size->x_i]->render_y;
	if (render_size->y_max < map[map_size->y_i][map_size->x_i]->render_y)
		render_size->y_max = map[map_size->y_i][map_size->x_i]->render_y;
	return (render_size);
}

t_window_data	*get_window_size(t_render_size	*render_size,
				t_window_data	*window_data)
{
	window_data->window_size_x
		= render_size->x_max - render_size->x_min + 20;
	window_data->window_size_y
		= render_size->y_max - render_size->y_min + 20;
	render_size->overflow_size_width
		= 0 - render_size->x_min;
	render_size->overflow_size_high
		= 0 - render_size->y_min;
	free(render_size);
	return (window_data);
}

static void	render_size_reset(t_render_size *render_size)
{
	render_size->x_min = 0;
	render_size->x_max = 0;
	render_size->y_min = 0;
	render_size->y_max = 0;
}

t_coordinate_data	***adjust_negative_coordinates(t_coordinate	*map_size,
						t_render_size	*render_size, t_coordinate_data ***map)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			map[map_size->y_i][map_size->x_i]->render_x
				+= render_size->overflow_size_width + 10;
			map[map_size->y_i][map_size->x_i]->render_y
				+= render_size->overflow_size_high + 10;
			map_size->x_i++;
		}
		map_size->x_i = 0;
		map_size->y_i++;
	}
	return (map);
}
