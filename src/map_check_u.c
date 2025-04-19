/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2025/04/18 17:29:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_x_size(char *read_buffer);

t_coordinate	*get_map_size(int fd, t_coordinate *map_size)
{
	int		x;
	char	*read_buffer;

	map_size->x = 0;
	while (1)
	{
		read_buffer = get_next_line(fd);
		if (read_buffer == NULL)
			break ;
		if (*read_buffer != '\n')
		{
			x = get_x_size(read_buffer);
			if (x >= map_size->x)
				map_size->x = x;
			map_size->y++;
		}
		free(read_buffer);
	}
	return (map_size);
}

int	get_x_size(char *read_buffer)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (read_buffer[i] != '\0')
	{
		if (ft_isdigit(read_buffer[i]))
		{
			while (ft_isdigit(read_buffer[i]))
				i++;
			x++;
		}
		if (read_buffer[i] != '\0')
			i++;
	}
	return (x);
}
