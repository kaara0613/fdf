/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/23 05:44:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	render_map(t_coordinate *map_size,
// 			t_coordinate_data ***map, t_window_data	*window_data)
// {
// 	map_size->x_i = 0;
// 	map_size->y_i = 0;
// 	while (map_size->y_i < map_size->y)
// 	{
// 		while (map_size->x_i < map_size->x)
// 		{
// 			mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
// 				map[map_size->y_i][map_size->x_i]->render_x,
// 				map[map_size->y_i][map_size->x_i]->render_y,
// 				map[map_size->y_i][map_size->x_i]->colar);
// 			map_size->x_i++;
// 		}
// 		map_size->y_i++;
// 		map_size->x_i = 0;
// 	}
// }

void	render_map(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			if (map_size->x_i + 1 < map_size->x)
				drawLineBresenham_x(map_size, map, window_data);
			if (map_size->y_i + 1 < map_size->y)
				drawLineBresenham_y(map_size, map, window_data);	
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
}
