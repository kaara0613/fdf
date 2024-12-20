/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 01:30:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_coordinate map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	map_size->x_i = 0;
	map_size->y_i = 0;
	while (map_size->y_i < map_size.y)
	{
		while (map_size->x_i < map_size.x)
		{
			mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
				map[map_size->y_i][map_size->x_i]->render_x,
				map[map_size->y_i][map_size->x_i]->render_y,
				map[map_size->y_i][map_size->x_i]->colar);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
}
