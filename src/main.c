/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2025/01/14 23:11:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_coordinate		*map_size;
	t_window_data		*window_data;
	t_coordinate_data	***map;

	if (argc != 2)
		return (0);
	map_size = NULL;
	window_data = NULL;
	map = NULL;
	window_data = window_data_allocate(map_size, window_data, map);
	map_size = map_check(argv[1], map_size, window_data, map);
	map = fdf_to_map(argv[1], map_size, window_data, map);
	map = make_render_map(map_size, window_data, map);
	window_data = make_mlx_window(window_data);
	render_map(map_size, window_data, map);
	control_mlx_window(window_data);
	free_map(0, map_size, window_data, map);
	return (0);
}
