/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/18 03:22:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate_data	make_coordinate_data(char	*char_map);
static void					free_char_map(t_coordinate map_size,
								char ***char_map);

char	***make_char_map(t_coordinate	map_size, int fd)
{
	char				*temp;
	char				***char_map;
	t_coordinate		coordinate_index;

	coordinate_index = reset_coordinate(coordinate_index);
	char_map = (char ***)malloc(sizeof(char **) * (map_size.y + 1));
	if (char_map == NULL)
		exit(EXIT_FAILURE);
	while (coordinate_index.y < map_size.y)
	{
		temp = get_next_line(fd);
		char_map[coordinate_index.y] = ft_split(temp, ' ');
		coordinate_index.y++;
		free(temp);
		temp = NULL;
	}
	return (char_map);
}

t_coordinate_data	**make_map(char ***char_map, t_coordinate	map_size)
{
	t_coordinate_data	**map;
	t_coordinate		coordinate_index;

	coordinate_index = reset_coordinate(coordinate_index);
	map = (t_coordinate_data **)malloc
		(sizeof(t_coordinate_data *) * (map_size.y + 1));
	if (map == NULL)
		exit (EXIT_FAILURE);
	while (coordinate_index.y <= map_size.y)
	{
		map[coordinate_index.y] = (t_coordinate_data *)malloc
			(sizeof(t_coordinate_data) * (map_size.x + 1));
		if (map == NULL)
			exit (EXIT_FAILURE);
		while (coordinate_index.x <= map_size.x)
		{
			map[coordinate_index.y][coordinate_index.x]
				= make_coordinate_data
				(char_map[coordinate_index.y][coordinate_index.x]);
			coordinate_index.x++;
		}
		coordinate_index.y++;
	}
	free_char_map(map_size, char_map);
	return (map);
}

t_coordinate	reset_coordinate(t_coordinate	coordinate_index)
{
	coordinate_index.x = 0;
	coordinate_index.y = 0;
	return (coordinate_index);
}

static t_coordinate_data	make_coordinate_data(char	*char_map)
{
	int					i;
	bool				flag;
	char				**temp;
	t_coordinate_data	map;

	temp = (char **)malloc(sizeof(char *) * 3);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	flag = false;
	while (char_map[i++])
	{
		if (char_map[i++] == ',')
			flag = true;
	}
	if (flag)
	{
		temp = ft_split(char_map, ',');
		map.z = ft_atoi(temp[0]);
		map.colar = ft_atoi(temp[1]);
	}
	else
		map.z = ft_atoi(char_map);
	free(temp);
	return (map);
}

static void	free_char_map(t_coordinate map_size, char ***char_map)
{
	t_coordinate	coordinate_index;

	coordinate_index = reset_coordinate(coordinate_index);
	while (coordinate_index.y < map_size.y)
	{
		while (coordinate_index.x < map_size.x)
		{
			free(char_map[coordinate_index.y][coordinate_index.x]);
			coordinate_index.x++;
		}
		free(char_map[coordinate_index.y]);
		coordinate_index.y++;
	}
	free(char_map);
}
