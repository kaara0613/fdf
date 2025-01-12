/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2025/01/12 21:03:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_coordinate		*map_size;
	t_window_data		*window_data;
	t_coordinate_data	***map;

	if (argc != 2)
		return (0);
	window_data = NULL;
	window_data = window_data_allocate(window_data);
	map_size = map_check(argv[1]);
	map = fdf_to_map(map_size, argv[1]);
	map = make_render_map(map_size, window_data, map);
	window_data = make_mlx_window(window_data);
	render_map(map_size, map, window_data);
	exit(0);
	control_mlx_window(window_data);
	free_map(map_size, window_data, map);
	return (0);
}
