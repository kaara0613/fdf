/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 20:06:12 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	update_segment_and_error(int err, t_segment	*segment);

void	draw_line_bresenham_x(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int			err;
	t_segment	*segment;

	segment = (t_segment *)malloc(sizeof(t_segment));
	if (segment == NULL)
		exit (EXIT_FAILURE);
	segment->x0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment->y0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment->x1 = map[map_size->y_i][map_size->x_i + 1]->render_x;
	segment->y1 = map[map_size->y_i][map_size->x_i + 1]->render_y;
	err = abs(segment->x1 - segment->x0) + -abs(segment->y1 - segment->y0);
	while (true)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			segment->x0, segment->y0, map[map_size->y_i][map_size->x_i]->colar);
		if (segment->x0 == segment->x1 && segment->y0 == segment->y1)
			break ;
		err = update_segment_and_error(err, segment);
	}
	free(segment);
}

void	draw_line_bresenham_y(t_coordinate *map_size,
			t_coordinate_data ***map, t_window_data	*window_data)
{
	int			err;
	t_segment	*segment;

	segment = (t_segment *)malloc(sizeof(t_segment));
	if (segment == NULL)
		exit (EXIT_FAILURE);
	segment->y0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment->x0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment->y1 = map[map_size->y_i + 1][map_size->x_i]->render_x;
	segment->x1 = map[map_size->y_i + 1][map_size->x_i]->render_y;
	err = abs(segment->x1 - segment->x0) + -abs(segment->y1 - segment->y0);
	while (true)
	{
		mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr,
			segment->y0, segment->x0, map[map_size->y_i][map_size->x_i]->colar);
		if (segment->x0 == segment->x1 && segment->y0 == segment->y1)
			break ;
		err = update_segment_and_error(err, segment);
	}
	free(segment);
}

static int	update_segment_and_error(int err, t_segment	*segment)
{
	if (2 * err >= -abs(segment->y1 - segment->y0))
	{
		err += -abs(segment->y1 - segment->y0);
		if (segment->x0 < segment->x1)
			segment->x0 += 1;
		else
			segment->x0 += -1;
	}
	if (2 * err <= abs(segment->x1 - segment->x0))
	{
		err += abs(segment->x1 - segment->x0);
		if (segment->y0 < segment->y1)
			segment->y0 = 1;
		else
			segment->y0 = -1;
	}
	return (err);
}
