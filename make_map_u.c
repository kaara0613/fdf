/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/13 18:16:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate_data	make_coordinate_data(char	*char_map);
static t_coordinate			*reset_coordinate(void);

t_coordinate_data	*make_char_map(int fd)
{
	t_coordinate_data	**map;
	t_coordinate		*coordinate_index;

	coordinate_index = reset_coordinate();
	map = (t_coordinate_data **)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		exit (EXIT_FAILURE);
	while (1)
	{
		map[coordinate_index->y]->char_map = get_next_line(fd);
		map[coordinate_index->y]
			= ft_split(map[coordinate_index->y], ' ');
		if (map[coordinate_index->y] == NULL)
			break ;
		coordinate_index->y++;
	}
	return (map);
}

t_coordinate_data	**make_map(t_coordinate_data **map)
{
	t_coordinate_data	**map;
	t_coordinate		*coordinate_index;

	coordinate_index = reset_coordinate();
	while (map[coordinate_index->y] != NULL)
	{
		while (map[coordinate_index->y][coordinate_index->x].char_map != NULL)
		{
			map[coordinate_index->y][coordinate_index->x]
				= make_coordinate_data(map[coordinate_index->y][coordinate_index->x].char_map);
			coordinate_index->y++;
		}
		coordinate_index->y++;
	}
	return (map);
}

static t_coordinate	*reset_coordinate(void)
{
	t_coordinate	*index;

	index = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (index == NULL)
		return (NULL);
	index->x = 0;
	index->y = 0;
	return (index);
}

static t_coordinate_data	make_coordinate_data(char	*char_map)
{
	char				**temp;
	t_coordinate_data	map;

	temp = (char **)malloc(sizeof(char));
	if (temp == NULL)
		return ;
	if (ft_strchr(char_map, ','))
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
