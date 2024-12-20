/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:25 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 17:31:18 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	t_window_data	*window_data;

	window_data = (t_window_data *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(window_data->mlx_ptr, window_data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

double	get_zoom_factor(t_coordinate map_size)
{
	double	zoom_factor;

	if (map_size.x <= map_size.y)
		zoom_factor = round((1000 / map_size.y) * 10) / 10;
	else
		zoom_factor = round((1000 / map_size.x) * 10) / 10;
	return (zoom_factor);
}
