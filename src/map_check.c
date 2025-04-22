/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:58:53 by kaara             #+#    #+#             */
/*   Updated: 2025/04/22 16:04:13 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_valid_extension(char *filename);

t_coordinate	*map_check(char *filename)
{
	int				fd;
	t_coordinate	*map_size;

	if (!is_valid_extension(filename))
	{
		perror("file error.");
		exit(EXIT_FAILURE);
	}
	map_size = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (map_size == NULL)
		exit (EXIT_FAILURE);
	map_size->x = 0;
	map_size->y = 0;
	fd = open(filename, O_RDONLY);
	if (!get_map_size(fd, map_size))
	{
		close(fd);
		perror("file error.");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (map_size);
}

static bool	is_valid_extension(char *filename)
{
	int		len;
	char	*s2;

	len = ft_strlen(filename);
	if (len <= 3)
		return (false);
	s2 = ft_strdup(".fdf");
	len -= 4;
	if (ft_strncmp(filename + len, s2, 4))
		return (free(s2), false);
	free(s2);
	return (true);
}

