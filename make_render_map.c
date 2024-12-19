/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 13:29:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	*make_render_coordinate(t_coordinate	coordinate_index,
										t_coordinate_data	*map)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = M_PI / 6;
	temp_x = (coordinate_index.x - coordinate_index.y) * cos(angle);
	temp_y = (coordinate_index.x + coordinate_index.y)
		* sin(angle) - map->z;
    zoom_map(temp_x, temp_y);
	map->render_x = (int)round(temp_x) + 10;
	map->render_y = (int)round(temp_y) + 10;
	return (map);
}
