/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 02:53:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_segment	update_segment_and_error(int *err, t_segment	segment);

void	draw_line_bresenham_x(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int			*err;
	t_segment	segment;

	segment.x0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment.y0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment.x1 = map[map_size->y_i][map_size->x_i + 1]->render_x;
	segment.y1 = map[map_size->y_i][map_size->x_i + 1]->render_y;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			segment.x0, segment.y0, map[map_size->y_i][map_size->x_i]->colar);
		if (segment.x0 == segment.x1 && segment.y0 == segment.y1)
			break ;
		segment = update_segment_and_error(err, segment);
	}
}

void	draw_line_bresenham_y(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int			*err;
	t_segment	segment;

	segment.y0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment.x0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment.y1 = map[map_size->y_i + 1][map_size->x_i]->render_x;
	segment.x1 = map[map_size->y_i + 1][map_size->x_i]->render_y;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			segment.y0, segment.x0, map[map_size->y_i][map_size->x_i]->colar);
		if (segment.x0 == segment.x1 && segment.y0 == segment.y1)
			break ;
		segment = update_segment_and_error(err, segment);
	}
}

static t_segment	update_segment_and_error(int *err, t_segment	segment)
{
	if (2 * *err >= dy)
	{
		*err += -abs(y1 - y0);
		if (x0 < x1)
			x0 += 1;
		else
			x0 += -1;
	}
	if (2 * *err <= dx)
	{
		*err += abs(x1 - x0);
		if (y0 < y1)
			y0 = 1;
		else
			y0 = -1;
	}
}
