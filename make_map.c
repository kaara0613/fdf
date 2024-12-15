/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/13 18:11:49 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	**fdf_to_map(char **argv)
{
	int					fd;
	t_coordinate_data	**map;

	fd = open(argv[1], O_RDONLY);
	map = make_map_char(fd);
	close(fd);
	map = make_map(map);
	if (map == NULL)
		return (NULL);
	return (map);
}
