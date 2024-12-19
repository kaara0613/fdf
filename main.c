/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 05:44:48 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	// t_window_data		*window_data;
	t_coordinate		map_size;
	t_coordinate_data	***map;

	if (argc <= 1)
		return (0);
	map_size = map_check(argv[1]);
	map = fdf_to_map(map_size, argv[1]);
	map = make_render_map(map_size, map);
	for (int y = 0; y < map_size.y; y++)
	{
		for (int x = 0; x < map_size.x; x++)
		{
			printf("%.2f,", map[y][x]->render_x);
			printf("%.2f", map[y][x]->render_y);
		}
		printf("\n");
	}
	free_map(map_size, map);
	// window_data = make_mlx_window();
	// render_map(window_data);
	// control_mlx_window(window_data);
	return (0);
}
