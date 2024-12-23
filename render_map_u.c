/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/23 05:52:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawLineBresenham_x(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int x0 = map[map_size->y_i][map_size->x_i]->render_x;
	int y0 = map[map_size->y_i][map_size->x_i]->render_y;
	int x1 = map[map_size->y_i][map_size->x_i + 1]->render_x;
	int y1 = map[map_size->y_i][map_size->x_i + 1]->render_y;
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			x0, y0, map[map_size->y_i][map_size->x_i]->colar);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void drawLineBresenham_y(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int y0 = map[map_size->y_i][map_size->x_i]->render_x;
	int x0 = map[map_size->y_i][map_size->x_i]->render_y;
	int y1 = map[map_size->y_i + 1][map_size->x_i]->render_x;
	int x1 = map[map_size->y_i + 1][map_size->x_i]->render_y;
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			y0, x0, map[map_size->y_i][map_size->x_i]->colar);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
