/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2025/04/22 16:02:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include <stdbool.h>

int	get_x_size(char *read_buffer);

bool	get_map_size(int fd, t_coordinate *map_size)
{
	int		flag;
	bool	result;
	char	*read_buffer;

	flag = 0;
	result = true;
	while (1)
	{
		read_buffer = get_next_line(fd);
		if (read_buffer != NULL && *read_buffer != '\n')
		{
			if (flag == 0)
			{
				map_size->x = get_x_size(read_buffer);
				flag = 1;
			}
			if (map_size->x != get_x_size(read_buffer))
				result = false;
			map_size->y++;
		}
		free(read_buffer);
		if (read_buffer == NULL)
			return (result);
	}
	return (result);
}

int	get_x_size(char *read_buffer)
{
	int		i;
	char	**after_split;

	i = 0;
	after_split = ft_split(read_buffer, ' ');
	while (after_split[i] != NULL)
	{
		free(after_split[i]);
		i++;
	}
	free(after_split);
	return (i);
}
