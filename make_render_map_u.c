/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:57 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 15:23:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	double				zoom_factor;
	t_coordinate	coordinate_index;

	coordinate_index.x = 0;
	coordinate_index.y = 0;
	zoom_factor = get_zoom_factor(map_size, window_data);
	while (coordinate_index.y < map_size.y)
	{
		while (coordinate_index.x < map_size.x)
		{
			map[coordinate_index.y][coordinate_index.x]
				= make_render_coordinate
				(coordinate_index, zoom_factor,
					map[coordinate_index.y][coordinate_index.x]);
			coordinate_index.x++;
		}
		coordinate_index.y++;
		coordinate_index.x = 0;
	}
	return (map);
}
