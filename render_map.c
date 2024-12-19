/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 05:40:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	render_map(t_window_data	*window_data)
// {
// 	mlx_pixel_put(window_data.mlx_ptr, window_data.win_ptr, 0, 0, 0x00FF0000);
// }

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_coordinate_data ***map)
{
	t_coordinate	coordinate_index;

			printf("a");
	coordinate_index = reset_coordinate(coordinate_index);
	while (coordinate_index.y < map_size.y)
	{
		while (coordinate_index.x < map_size.x)
		{
			map[coordinate_index.y][coordinate_index.x]
				= make_render_coordinate
				(coordinate_index, map[coordinate_index.y][coordinate_index.x]);
			// printf("%.2f", map[coordinate_index.y][coordinate_index.x]->render_x);
			coordinate_index.x++;
		}
		coordinate_index.y++;
		coordinate_index.x = 0;
	}
	return (map);
}
