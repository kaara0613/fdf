/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2025/01/13 15:13:42 by marvin           ###   ########.fr       */
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
	printf("1\n");
	window_data = window_data_allocate(window_data);
	printf("1\n");
	map_size = map_check(argv[1]);
	printf("1\n");
	map = fdf_to_map(map_size, argv[1]);
	printf("1\n");
	map = make_render_map(map_size, window_data, map);
	printf("1\n");
	window_data = make_mlx_window(window_data);
	printf("1\n");
	render_map(map_size, map, window_data);
	printf("1\n");
	control_mlx_window(window_data);
	printf("1\n");
	free_map(map_size, window_data, map);
	return (0);
}
