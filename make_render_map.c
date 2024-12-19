/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 15:23:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	*make_render_coordinate(t_coordinate	coordinate_index,
						double zoom_factor, t_coordinate_data	*map)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = M_PI / 6;
	temp_x = (coordinate_index.x - coordinate_index.y) * cos(angle);
	temp_y = (coordinate_index.x + coordinate_index.y)
		* sin(angle) - map->z;
	map->render_x = (int)(round(temp_x * zoom_factor) + 10);
	map->render_y = (int)(round(temp_y * zoom_factor) + 10);
	return (map);
}

double	get_zoom_factor(t_coordinate map_size, t_window_data	*window_data)
{
	double zoom_factor;

	if (map_size.x <= map_size.y)
		zoom_factor = window_data->window_size / map_size.y
}