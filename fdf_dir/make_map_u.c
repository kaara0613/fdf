/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/10 22:37:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_coordinate(t_coordinate *origin)
{
	origin->x = 0;
	origin->y = 0;
}

bool	count_element(int fd, t_coordinate *max)
{
	open(.fdf O_RDONLY);

}

void	make_map_char(int fd, char **map_char, t_coordinate *make_max_index)
{
	while (**map_char[make_max_index->y] != NULL)
	{
		**map_char[make_max_index->y] = get_next_line(fd);
		while (*map_char[make_max_index->y][make_max_index->x] != NULL)
			*map_char[make_max_index->y][make_max_index->x++]
				= ft_sprit(map_char[make_max_index->y], ' ');
		make_max_index->y++;
	}
}
