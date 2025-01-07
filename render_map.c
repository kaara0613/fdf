/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2025/01/06 12:53:29 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			if (map_size->x_i + 1 < map_size->x)
				draw_line_bresenham_x(map_size, map, window_data);
			if (map_size->y_i + 1 < map_size->y)
				draw_line_bresenham_y(map_size, map, window_data);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
}
