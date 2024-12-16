/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2024/12/16 05:05:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate	*get_map_size(int fd, t_coordinate *map_size)
{
	ssize_t	read_size;
	char	*read_buffer;

	read_size = 0;
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		exit (1);
	read_size = read(fd, read_buffer, BUFFER_SIZE + 1);
	if (read_size < 0)
	{
		free(read_buffer);
		exit (1);
	}
	if (read_size == 0)
		return (map_size);
	if (read_buffer[map_size->x] == '\0')
	{
		if (read_buffer[map_size->y] == ' ')
			map_size->y++;
		map_size->x++;
	}
}
