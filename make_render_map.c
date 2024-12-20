/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 01:58:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	*make_render_coordinate(t_coordinate	coordinate_index,
						double zoom_factor, t_coordinate_data	*map)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = M_PI / 6;
	temp_x = (map_size->x_i - map_size->y_i) * cos(angle);
	temp_y = (map_size->x_i + map_size->y_i)
		* sin(angle) - map->z;
	map->render_x = (int)(round(temp_x * zoom_factor));
	map->render_y = (int)(round(temp_y * zoom_factor));
	return (map);
}
