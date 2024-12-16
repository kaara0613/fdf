/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:58:53 by kaara             #+#    #+#             */
/*   Updated: 2024/12/16 08:41:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate	*map_check(char *filename)
{
	int				fd;
	t_coordinate	*map_size;

	map_size = reset_coordinate();
	fd = open(filename, O_RDONLY);
	map_size = get_map_size(fd, map_size);
	close(fd);
	return (map_size);
}
