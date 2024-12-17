/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2024/12/17 12:09:51 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate	*get_map_size(int fd, t_coordinate *map_size)
{
	int		i;
	char	*read_buffer;

	while (1)
	{
		read_buffer = get_next_line(fd);
		if (read_buffer == NULL)
			break ;
		i = 0;
		map_size->x = 0;
		while (read_buffer[i++] != '\0')
		{
			if (read_buffer[i] == ' ' && read_buffer[i + 1] == ' ')
			{
				map_size->x++;
				i++;
			}
			else if (read_buffer[i] == ' ')
				map_size->x++;
		}
		map_size->y++;
		free(read_buffer);
	}
	map_size->x++;
	return (map_size);
}

// t_coordinate	*get_map_size(int fd, t_coordinate *map_size)
// {
// 	ssize_t	read_size;
// 	char	*read_buffer;

// 	read_size = 0;
// 	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!read_buffer)
// 		exit (1);
// 	read_size = read(fd, read_buffer, BUFFER_SIZE + 1);
// 	if (read_size < 0)
// 	{
// 		free(read_buffer);
// 		exit(EXIT_FALSE);
// 	}
// 	if (read_size == 0)
// 		return (map_size);
// 	read_buffer[read_size + 1] = '\0';
// 	while (read_buffer++ != '\0')
// 	{
// 		if (read_buffer == '\n')
// 			map_size->y++;
// 		if (read_buffer == ' ')
// 			map_size->x++;
// 	}
// 	get_map_size(fd, map_size);
// }