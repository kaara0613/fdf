/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 13:49:48 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	map_size.x_i = 0;
	map_size.y_i = 0;
	while (map_size.y_i < map_size.y)
	{
		while (map_size.x_i < map_size.x)
		{
			map[map_size.y_i][map_size.x_i]
				= make_render_coordinate
				(map_size, window_data->zoom_factor,
					map[map_size.y_i][map_size.x_i]);
			map_size.x_i++;
		}
		map_size.y_i++;
		map_size.x_i = 0;
	}
	return (map);
}
