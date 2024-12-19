/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 03:46:27 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_coordinate(t_coordinate	map_index,
										t_coordinate_data	***map)
{
	double	angle;

	angle = M_PI / 6;
	map[map_index.y][map_index.x]->render_x
		= (map_index.x - map_index.y) * cos(angle);
	map[map_index.y][map_index.x]->render_y
		= (map_index.x + map_index.y)
		* sin(angle) - map[map_index.y][map_index.x]->z;
	return (map);
}
