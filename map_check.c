/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:58:53 by kaara             #+#    #+#             */
/*   Updated: 2025/01/06 12:56:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate	*map_check(char *filename)
{
	int				fd;
	t_coordinate	*map_size;

	map_size = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (map_size == NULL)
		exit (EXIT_FAILURE);
	map_size->x = 0;
	map_size->y = 0;
	fd = open(filename, O_RDONLY);
	map_size = get_map_size(fd, map_size);
	close(fd);
	return (map_size);
}
