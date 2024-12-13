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

static t_coordinate_data	*make_coordinate_data(char	***map_char, \
	t_coordinate	*coordinate_index);
static t_coordinate	*reset_coordinate(void);

char	***make_map_char(int fd)
{
	char			***map_char;
	t_coordinate	*coordinate_index;

	coordinate_index = reset_coordinate();
	map_char = (char ***)malloc(sizeof(char));
	if (map_char == NULL)
		return (NULL);
	while (1)
	{
		*(map_char[coordinate_index->y]) = get_next_line(fd);
		map_char[coordinate_index->y]
			= ft_split(*map_char[coordinate_index->y], ' ');
		if (*map_char[coordinate_index->y])
			break ;
		coordinate_index->y++;
	}
	return (map_char);
}

t_coordinate_data	***make_map(char ***map_char)
{
	t_coordinate_data	***map;
	t_coordinate		*coordinate_index;

	map = (t_coordinate_data ***)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		return (NULL);
	coordinate_index = reset_coordinate();
	while (map_char[coordinate_index->y] != NULL)
	{
		while (map_char[coordinate_index->y][coordinate_index->x] != NULL)
		{
			map[coordinate_index->y][coordinate_index->x]
				= make_coordinate_data(map_char, coordinate_index);
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

static t_coordinate_data	*make_coordinate_data(char	***map_char,
	t_coordinate	*coordinate_index)
{
	char				**temp;
	t_coordinate_data	*map;

	map = (t_coordinate_data *)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		return (NULL);
	temp = (char **)malloc(sizeof(char));
	if (temp == NULL)
		return (NULL);
	if (ft_strchr(map_char[coordinate_index->y]
			[coordinate_index->x], ','))
	{
		temp = ft_split(map_char[coordinate_index->y]
			[coordinate_index->x], ',');
		map->z = ft_atoi(temp[0]);
		map->colar = ft_atoi(temp[1]);
	}
	else
		map->z = ft_atoi(map_char[coordinate_index->y][coordinate_index->x]);
	free(temp);
	return (map);
}
