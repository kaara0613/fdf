/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/23 10:24:36 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate_data	*make_coordinate_data(char	*char_map);

char	***make_char_map(t_coordinate	*map_size, int fd)
{
	char				*temp;
	char				***char_map;

	reset_map_index(map_size);
	char_map = (char ***)malloc(sizeof(char **) * (map_size->y + 1));
	if (char_map == NULL)
		free_map(1, map_size, window_data, map);
	while (map_size->y_i < map_size->y)
	{
		temp = get_next_line(fd);
		char_map[map_size->y_i] = ft_split(temp, ' ');
		map_size->y_i++;
		free(temp);
		temp = NULL;
	}
	return (char_map);
}

t_coordinate_data	***make_map(t_coordinate	*map_size, char ***char_map)
{
	t_coordinate_data	***map;

	reset_map_index(map_size);
	map = (t_coordinate_data ***)malloc
		(sizeof(t_coordinate_data **) * (map_size->y));
	if (map == NULL)
		free_map(1, map_size, window_data, map);
	while (map_size->y_i < map_size->y)
	{
		map[map_size->y_i] = (t_coordinate_data **)malloc
			(sizeof(t_coordinate_data *) * (map_size->x));
		if (map[map_size->y_i] == NULL)
			free_map(1, map_size, window_data, map);
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

static t_coordinate_data	*make_coordinate_data(char	*char_map)
{
	int					i;
	bool				flag;
	char				**temp;
	t_coordinate_data	*map;

	if (char_map == NULL)
		return (NULL);
	map = (t_coordinate_data *)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		free_map(1, map_size, window_data, map);
	i = 0;
	flag = false;
	while (char_map[i] != '\0')
	{
		if (char_map[i] == ',')
			flag = true;
		i++;
	}
	if (flag)
	{
		temp = ft_split(char_map, ',');
		map->z = ft_atoi(temp[0]);
		map->colar = 0xFFFFFFFF; //ft_atoi(temp[1]);
		free(temp[0]);
		free(temp[1]);
		free(temp);
	}
	else
	{
		map->z = ft_atoi(char_map);
		map->colar = 0xFFFFFFFF;
	}
	return (map);
}

void	free_char_map(t_coordinate *map_size, char ***char_map)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
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
