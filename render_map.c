/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 08:27:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	render_map(t_coordinate map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	t_coordinate_data *inner;
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map_size.y)
	{
		while (x < map_size.x)
		{
			inner = map[y][x];
			printf("%d %d %d", inner -> render_x, inner -> render_y, inner -> colar);

			mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
				inner -> render_x,
				inner -> render_y,
				inner -> colar
			);
			x += 1;		
		}
		y += 1;
		x = 0;
	}
}

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_coordinate_data ***map)
{
	t_coordinate	coordinate_index;

	coordinate_index = reset_coordinate(coordinate_index);
	while (coordinate_index.y < map_size.y)
	{
		while (coordinate_index.x < map_size.x)
		{
			map[coordinate_index.y][coordinate_index.x]
				= make_render_coordinate
				(coordinate_index, map[coordinate_index.y][coordinate_index.x]);
			coordinate_index.x++;
		}
		coordinate_index.y++;
		coordinate_index.x = 0;
	}
	return (map);
}
