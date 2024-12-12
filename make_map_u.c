/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/12 13:29:31 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_coordinate(t_coordinate *origin)
{
	origin->x = 0;
	origin->y = 0;
}

char	***make_map_char(int fd)
{
	char			***map_char;
	t_coordinate	*coordinate_index;

	reset_coordinate(coordinate_index);
	while (1)
	{
		*map_char[coordinate_index->y] = get_next_line(fd);
		map_char[coordinate_index->y]
			= ft_sprit(*map_char[coordinate_index->y], ' ');
		if (*map_char[coordinate_index->y])
			break ;
		coordinate_index->y++;
	}
	return (map_char);
}

t_coordinate_data	**make_map(char ***map_char)
{
	t_coordinate_data	**map;
	t_coordinate		*coordinate_index;

	reset_coordinate(coordinate_index);
	while (coordinate_index->y != NULL)
	{
		while (coordinate_index->x != NULL)
		{
			map[coordinate_index->y][coordinate_index->x]
				= make_coordinate_data(map_char, coordinate_index);
			coordinate_index->y++;
		}
		coordinate_index->y++;
	}
	return (map);
}

t_coordinate_data	make_coordinate_data(char	***map_char,
	t_coordinate	*coordinate_index)
{
	char				**temp;
	t_coordinate_data	map;

	if (strchar(map_char[coordinate_index->x]
			[coordinate_index->y], ','))
	{
		temp = split(map_char[coordinate_index->x]
			[coordinate_index->y], ',');
		map.z = atoi(temp[0]);
		map.colar = atoi(temp[1]);
	}
	else
		map.z = atoi(map_char[coordinate_index->x][coordinate_index->y]);
}
