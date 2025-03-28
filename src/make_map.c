/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2025/01/14 23:11:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coordinate_data	***fdf_to_map(char *filename, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	int					fd;
	char				***char_map;

	fd = open(filename, O_RDONLY);
	char_map = make_char_map(fd, map_size, window_data, map);
	close(fd);
	map = make_map(map_size, window_data, char_map, map);
	free_char_map(map_size, char_map);
	return (map);
}

void	free_map(int error_flag, t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data ***map)
{
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
	if (error_flag == 1)
		exit(EXIT_FAILURE);
}
