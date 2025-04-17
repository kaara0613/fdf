/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2025/04/17 14:32:07 by kaara            ###   ########.fr       */
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
		while (read_buffer[i] != '\0')
		{
			if (ft_isdigit(read_buffer[i]))
			{
				while (ft_isdigit(read_buffer[i]))
					i++;
				map_size->x++;
			}
			i++;
		}
		map_size->y++;
		free(read_buffer);
	}
	map_size->y -= 1;
	return (map_size);
}
