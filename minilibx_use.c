/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:44 by kaara             #+#    #+#             */
/*   Updated: 2024/12/20 01:58:02 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window_data	*make_mlx_window(t_coordinate	map_size,
					t_coordinate_data	***map)
{
	t_window_data		*window_data;

	window_data = malloc(sizeof(t_window_data));
	if (window_data == NULL)
		exit (EXIT_FAILURE);
	window_data->mlx_ptr = mlx_init();
	if (window_data->mlx_ptr == NULL)
		return (free(window_data), NULL);
	window_data->win_ptr
		= mlx_new_window
		(window_data->mlx_ptr,
			map[map_size->x][map_size->y]->render_x + 10,
			map[map_size->x][map_size->y]->render_y + 10, "fdf");
	if (window_data->win_ptr == NULL)
		return (free(window_data), NULL);
	t_window_data->zoom_factor = get_zoom_factor(map_size);
	mlx_clear_window(window_data->mlx_ptr, window_data->win_ptr);
	return (window_data);
}

void	control_mlx_window(t_window_data *window_data)
{
	mlx_key_hook(window_data->win_ptr, key_hook, window_data);
	mlx_loop(window_data->mlx_ptr);
}
