/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/10 22:37:21 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**make_map(int fd, t_coordinate *max)
{
	char			***map_char;
	t_coordinate	*make_max_index;

	reset_coordinate(make_max_index);
	//open

	make_map_char(map_char, make_max_index);

	//close
	reset_coordinate(make_max_index);
	while (make_max_index->y <= max->y)
	{
		while (make_max_index->x <= max->x)
		{
			build_coordinate(map_char, map);
			make_max_index->y++;
		}
		make_max_index->y++;
	}
	return (map);
}
