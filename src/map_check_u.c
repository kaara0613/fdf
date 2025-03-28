/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 03:05:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		if (ft_isdigit(read_buffer[i]))//|| read_buffer[i] == '+' || read_buffer[i] == '-'))
			map_size->x++;
		while (read_buffer[i] != '\0')
		{
			if (read_buffer[i] == ' ' && ft_isdigit(read_buffer[i + 1]))//|| read_buffer[i + 1] == '+' || read_buffer[i + 1] == '-'))
				map_size->x++;
			i++;
		}
		map_size->y++;
		free(read_buffer);
	}
	map_size->y -= 1;
	return (map_size);
}
