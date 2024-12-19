/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:57 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 12:55:08 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_coordinate_data ***map)
{
	t_coordinate	coordinate_index;

	coordinate_index.x = 0;
	coordinate_index.y = 0;
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
