/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2025/01/07 22:31:32 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_coordinate		*map_size;
	t_window_data		*window_data;
	t_coordinate_data	***map;
	char				**xpm_data;

	if (argc != 2)
		return (0);
	window_data = NULL;
	window_data = window_data_allocate(window_data);
	map_size = map_check(argv[1]);
	map = fdf_to_map(map_size, argv[1]);
	map = make_render_map(map_size, window_data, map);
	window_data = make_mlx_window(window_data);
	xpm_data = make_xpm_data(window_data);
	render_map(map_size, map, xpm_data);
	for (int i = 0; i <= window_data->window_size_y + 3; i++)
	{
		if (xpm_data[i] == NULL)
			printf("NULL\n");
		else
			printf("%s\n", xpm_data[i]);
	}
	control_mlx_window(xpm_data, window_data);
	free_xpm(xpm_data, window_data);
	free_map(map_size, window_data, map);
	return (0);
}
