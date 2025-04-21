/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2025/04/21 16:27:23 by kaara            ###   ########.fr       */
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

t_coordinate_data	***make_map(t_coordinate	*map_size, char ***char_map)
{
	t_coordinate_data	***map;

	reset_map_index(map_size);
	map = (t_coordinate_data ***)malloc
		(sizeof(t_coordinate_data **) * (map_size->y));
	if (map == NULL)
		exit (EXIT_FAILURE);
	while (map_size->y_i < map_size->y)
	{
		map[map_size->y_i] = (t_coordinate_data **)malloc
			(sizeof(t_coordinate_data *) * (map_size->x));
		if (map[map_size->y_i] == NULL)
			exit (EXIT_FAILURE);
		while (map_size->x_i < map_size->x)
		{
			map[map_size->y_i][map_size->x_i]
				= make_coordinate_data
				(char_map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (map);
}

void	free_map(t_coordinate	*map_size, t_coordinate_data ***map)
{
	map_size->x_i = 0;
	map_size->y_i = 0;
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
}

void	free_char_map(t_coordinate *map_size, char ***char_map)
{
	map_size->x_i = 0;
	map_size->y_i = 0;
	while (map_size->y_i < map_size->y)
	{
		while (char_map[map_size->y_i][map_size->x_i] != NULL)
		{
			free(char_map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		free(char_map[map_size->y_i]);
		map_size->y_i++;
		map_size->x_i = 0;
	}
	free(char_map);
}
