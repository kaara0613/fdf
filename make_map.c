/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/18 06:57:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	**fdf_to_map(t_coordinate map_size, char *filename)
{
	int					fd;
	char				***char_map;
	t_coordinate_data	**map;

	fd = open(filename, O_RDONLY);
	char_map = make_char_map(map_size, fd);
	close(fd);
	map = make_map(char_map, map_size);
	free_char_map(map_size, char_map);
	return (map);
}

void	free_map(t_coordinate	map_size, t_coordinate_data **map)
{
	t_coordinate	coordinate_index;

	coordinate_index = reset_coordinate(coordinate_index);
	while (coordinate_index.y < map_size.y)
	{
		free(map[coordinate_index.y]);
		coordinate_index.y++;
	}

	free(map);
}
