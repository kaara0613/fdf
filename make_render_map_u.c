/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:57 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 14:23:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	*make_render_coordinate(t_coordinate	map_size,
						double zoom_factor, t_coordinate_data	*map)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = M_PI / 6;
	temp_x = (map_size.x_i - map_size.y_i) * cos(angle);
	temp_y = (map_size.x_i + map_size.y_i)
		* sin(angle) - map->z;
	map->render_x = (int)(round(temp_x * zoom_factor)) + 350;
	map->render_y = (int)(round(temp_y * zoom_factor)) + 350;
	return (map);
}
