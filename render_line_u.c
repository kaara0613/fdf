/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:32 by kaara             #+#    #+#             */
/*   Updated: 2025/01/07 20:46:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	reset_segment_and_error(int err, t_segment	*segment);
static int	update_segment_and_error(int err, t_segment	*segment);

void	draw_line_bresenham_x(t_coordinate *map_size, t_coordinate_data ***map,
			char **xpm_data)
{
	int			err;
	t_segment	*segment;

	err = 1;
	segment = (t_segment *)malloc(sizeof(t_segment));
	if (segment == NULL)
		exit (EXIT_FAILURE);
	segment->x0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment->y0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment->x1 = map[map_size->y_i][map_size->x_i + 1]->render_x;
	segment->y1 = map[map_size->y_i][map_size->x_i + 1]->render_y;
	err = reset_segment_and_error(err, segment);
	while (true)
	{
		xpm_data[map[map_size->y_i][map_size->x_i]->render_y]
		[map[map_size->y_i][map_size->x_i]->render_x] = '.';
		if (segment->x0 == segment->x1 && segment->y0 == segment->y1)
			break ;
		err = update_segment_and_error(err, segment);
	}
	free(segment);
}

void	draw_line_bresenham_y(t_coordinate *map_size, t_coordinate_data ***map,
			char **xpm_data)
{
	int			err;
	t_segment	*segment;

	err = 1;
	segment = (t_segment *)malloc(sizeof(t_segment));
	if (segment == NULL)
		exit (EXIT_FAILURE);
	segment->y0 = map[map_size->y_i][map_size->x_i]->render_x;
	segment->x0 = map[map_size->y_i][map_size->x_i]->render_y;
	segment->y1 = map[map_size->y_i + 1][map_size->x_i]->render_x;
	segment->x1 = map[map_size->y_i + 1][map_size->x_i]->render_y;
	err = reset_segment_and_error(err, segment);
	while (true)
	{
		xpm_data[map[map_size->y_i][map_size->x_i]->render_y]
		[map[map_size->y_i][map_size->x_i]->render_x] = '.';
		if (segment->x0 == segment->x1 && segment->y0 == segment->y1)
			break ;
		err = update_segment_and_error(err, segment);
	}
	free(segment);
}

static int	reset_segment_and_error(int err, t_segment *segment)
{
	segment->dx = abs(segment->x1 - segment->x0);
	segment->dy = abs(segment->y1 - segment->y0);
	if (segment->x0 < segment->x1)
		segment->sx = 1;
	else
		segment->sx = -1;
	if (segment->y0 < segment->y1)
		segment->sy = 1;
	else
		segment->sy = -1;
	err = (segment->dx - segment->dy);
	return (err);
}

static int	update_segment_and_error(int err, t_segment	*segment)
{
	int	e2;

	e2 = 2 * err;
	if (e2 > -(segment->dy))
	{
		err -= segment->dy;
		segment->x0 += segment->sx;
	}
	if (e2 < segment->dx)
	{
		err += segment->dx;
		segment->y0 += segment->sy;
	}
	return (err);
}
