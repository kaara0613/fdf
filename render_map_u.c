/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 18:46:26 by kaara            ###   ########.fr       */
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
	map->render_x = (int)((round(temp_x) + 10) * 10);
	map->render_y = (int)((round(temp_y) + 10) * 10);
	return (map);
}
