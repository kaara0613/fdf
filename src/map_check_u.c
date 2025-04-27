/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:59:51 by kaara             #+#    #+#             */
/*   Updated: 2025/04/27 16:07:43 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include <stdbool.h>

static bool	check_x_size(int flag, char *read_buffer, t_coordinate *map_size);
static int	get_x_size(char *read_buffer);

bool	get_map_size(int fd, t_coordinate *map_size)
{
	int		flag;
	bool	result;
	char	*read_buffer;


	result = true;
	flag = 0;
	map_size->y = 0;
	while (1)
	{
		read_buffer = get_next_line(fd);
		if (read_buffer != NULL && *read_buffer != '\n')
		{
			if (!check_x_size(flag, read_buffer, map_size))
				result = false;
			map_size->y++;
		}
		free(read_buffer);
		if (read_buffer == NULL)
			return (result);
	}
	return (result);
}

static bool	check_x_size(int flag, char *read_buffer, t_coordinate *map_size)
{
	if (flag == 0)
	{
		map_size->x = get_x_size(read_buffer);
		flag = 1;
	}
	if (map_size->x != get_x_size(read_buffer))
		return (false);
	return (true);
}

static int	get_x_size(char *read_buffer)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (read_buffer[i] != '\n' && read_buffer[i] != '\0')
	{
		if (ft_isalpha(read_buffer[i])
			|| ft_isdigit(read_buffer[i])
			|| read_buffer[i] == ',')
		{
			while (ft_isalpha(read_buffer[i])
				|| ft_isdigit(read_buffer[i])
				|| read_buffer[i] == ',')
				i++;
			result++;
		}
		i++;
	}
	return (result);
}
