/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 05:49:31 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	*make_render_coordinate(t_coordinate	coordinate_index,
										t_coordinate_data	*map)
{
	double	angle;

	angle = M_PI / 6;
	map->render_x = (coordinate_index.x - coordinate_index.y) * cos(angle);
	map->render_y = (coordinate_index.x + coordinate_index.y)
		* sin(angle) - map->z;
	return (map);
}
