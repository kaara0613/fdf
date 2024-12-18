/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 12:52:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_coordinate map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	t_coordinate	coordinate_index;

	coordinate_index.x = 0;
	coordinate_index.y = 0;
	while (coordinate_index.y < map_size.y)
	{
		while (coordinate_index.x < map_size.x)
		{
			mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
				map[coordinate_index.y][coordinate_index.x]->render_x,
				map[coordinate_index.y][coordinate_index.x]->render_y,
				map[coordinate_index.y][coordinate_index.x]->colar);
			coordinate_index.x++;
		}
		coordinate_index.y++;
		coordinate_index.x = 0;
	}
}
