/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2025/01/07 20:54:57 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	***fdf_to_map(t_coordinate *map_size, char *filename)
{
	int					fd;
	char				***char_map;
	t_coordinate_data	***map;

	fd = open(filename, O_RDONLY);
	char_map = make_char_map(map_size, fd);
	close(fd);
	map = make_map(map_size, char_map);
	free_char_map(map_size, char_map);
	return (map);
}

void	free_map(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data ***map)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			free(map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		free(map[map_size->y_i]);
		map_size->y_i++;
		map_size->x_i = 0;
	}
	free(map);
	free(map_size);
	free(window_data);
	mlx_destroy_image(window_data->mlx_ptr, window_data->img_ptr);
}
