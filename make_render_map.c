/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:53:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 15:41:16 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***make_render_map(t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	t_render_size	*render_size;

	render_size = NULL;
	window_data->zoom_factor = get_zoom_factor(map_size, map);
	map = update_map_to_pixels(map_size, window_data, map);
	render_size = check_render_size(map_size, window_data, map);
	window_data = get_window_size(render_size, window_data);
	map = adjust_negative_coordinates(map_size, render_size, map);
	return (map);
}
