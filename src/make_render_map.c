/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2025/04/17 14:06:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	t_render_size	*render_size;

	render_size = NULL;
	window_data->zoom_factor = get_zoom_factor(map_size, map);
	map = update_map_to_pixels(map_size, window_data, map);
	render_size = check_render_size(map_size, map);
	get_window_size(render_size, window_data);
	map = adjust_negative_coordinates(map_size, render_size, map);
	return (map);
}

void	get_window_size(t_render_size	*render_size,
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
	free(render_size);
	return (map);
}
