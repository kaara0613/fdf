/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/22 12:55:06 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	t_render_size	*render_size;

	render_size = NULL;
	update_map_to_pixels(map_size, window_data, map);
	check_render_size(map_size, map);
	render_size = get_window_size(render_size, window_data);
	map = adjust_negative_coordinates(render_size, map);
	return (map);
}
